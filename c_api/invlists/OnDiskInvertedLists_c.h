/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c -*-

#ifndef FAISS_ON_DISK_INVERTED_LISTS_C_H
#define FAISS_ON_DISK_INVERTED_LISTS_C_H

#include <stdint.h>
#include <stdlib.h>
#include "../faiss_c.h"
#include "InvertedLists_c.h"

#ifdef __cplusplus
extern "C" {
#endif

/** On-disk storage of inverted lists.
 *
 * The data is stored in a mmapped chunk of memory (base pointer ptr,
 * size totsize). Each list is a range of memory that contains (object
 * List) that contains:
 *
 * - uint8_t codes[capacity * code_size]
 * - followed by idx_t ids[capacity]
 *
 * in each of the arrays, the size <= capacity first elements are
 * used, the rest is not initialized.
 *
 * Addition and resize are supported by:
 * - roundind up the capacity of the lists to a power of two
 * - maintaining a list of empty slots, sorted by size.
 * - resizing the mmapped block is adjusted as needed.
 *
 * An OnDiskInvertedLists is compact if the size == capacity for all
 * lists and there are no available slots.
 *
 * Addition to the invlists is slow. For incremental add it is better
 * to use a default ArrayInvertedLists object and convert it to an
 * OnDisk with merge_from.
 *
 * When it is known that a set of lists will be accessed, it is useful
 * to call prefetch_lists, that launches a set of threads to read the
 * lists in parallel.
 */
FAISS_DECLARE_CLASS_INHERITED(OnDiskInvertedLists, InvertedLists)
FAISS_DECLARE_DESTRUCTOR(OnDiskInvertedLists)

FAISS_DECLARE_GETTER(OnDiskInvertedLists, const char*, filename)
FAISS_DECLARE_SETTER(OnDiskInvertedLists, const char*, filename)

int faiss_OnDiskInvertedLists_new(
        FaissOnDiskInvertedLists** invlists,
        size_t nlist,
        size_t code_size,
        const char* filename);

// copy all inverted lists into *this, in compact form (without
// allocating slots)
int faiss_OnDiskInvertedLists_merge_from_multiple(
        FaissOnDiskInvertedLists* invlists,
        const FaissInvertedLists** ils,
        int n_il,
        int shift_ids,
        int verbose);

#ifdef __cplusplus
}
#endif

#endif