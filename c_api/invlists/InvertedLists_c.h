/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c -*-

#ifndef FAISS_INVERTED_LISTS_C_H
#define FAISS_INVERTED_LISTS_C_H

#include <stddef.h>
#include "../faiss_c.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Table of inverted lists
 * multithreading rules:
 * - concurrent read accesses are allowed
 * - concurrent update accesses are allowed
 * - for resize and add_entries, only concurrent access to different lists
 *   are allowed
 */
FAISS_DECLARE_CLASS(InvertedLists)
FAISS_DECLARE_DESTRUCTOR(InvertedLists)

/*****************************************************************
 * Meta-inverted lists
 *
 * About terminology: the inverted lists are seen as a sparse matrix,
 * that can be stacked horizontally, vertically and sliced.
 *****************************************************************/

/// invlists that fail for all write functions
FAISS_DECLARE_CLASS_INHERITED(ReadOnlyInvertedLists, InvertedLists)
FAISS_DECLARE_DESTRUCTOR(ReadOnlyInvertedLists)

/// Horizontal stack of inverted lists
FAISS_DECLARE_CLASS_INHERITED(HStackInvertedLists, ReadOnlyInvertedLists)
FAISS_DECLARE_DESTRUCTOR(HStackInvertedLists)

/// vertical slice of indexes in another InvertedLists
FAISS_DECLARE_CLASS_INHERITED(SliceInvertedLists, ReadOnlyInvertedLists)
FAISS_DECLARE_DESTRUCTOR(SliceInvertedLists)

FAISS_DECLARE_CLASS_INHERITED(VStackInvertedLists, ReadOnlyInvertedLists)
FAISS_DECLARE_DESTRUCTOR(VStackInvertedLists)

/** use the first inverted lists if they are non-empty otherwise use the second
 *
 * This is useful if il1 has a few inverted lists that are too long,
 * and that il0 has replacement lists for those, with empty lists for
 * the others. */
FAISS_DECLARE_CLASS_INHERITED(MaskedInvertedLists, ReadOnlyInvertedLists)
FAISS_DECLARE_DESTRUCTOR(MaskedInvertedLists)

/** if the inverted list in il is smaller than maxsize then return it,
 *  otherwise return an empty invlist */
FAISS_DECLARE_CLASS_INHERITED(StopWordsInvertedLists, ReadOnlyInvertedLists)
FAISS_DECLARE_DESTRUCTOR(StopWordsInvertedLists)

FAISS_DECLARE_CLASS_INHERITED(ArrayInvertedLists, InvertedLists)
FAISS_DECLARE_DESTRUCTOR(ArrayInvertedLists)

int faiss_ArrayInvertedLists_new(
        FaissArrayInvertedLists** p_invlists,
        size_t nlist,
        size_t code_size);

int faiss_HStackInvertedLists_new(
        FaissHStackInvertedLists** p_invlists,
        int nil,
        const FaissInvertedLists** ils);

int faiss_SliceInvertedLists_new(
        FaissSliceInvertedLists** p_invlists,
        const FaissInvertedLists* il,
        idx_t i0,
        idx_t i1);

int faiss_VStackInvertedLists_new(
        FaissVStackInvertedLists** p_invlists,
        int nil,
        const FaissInvertedLists** ils);

int faiss_MaskedInvertedLists_new(
        FaissMaskedInvertedLists** p_invlists,
        const FaissInvertedLists* il0,
        const FaissInvertedLists* il1);

int faiss_StopWordsInvertedLists_new(
        FaissStopWordsInvertedLists** p_invlists,
        const FaissInvertedLists* il,
        size_t maxsize);

// Aliases
typedef FaissHStackInvertedLists FaissConcatenatedInvertedLists;

#ifdef __cplusplus
}
#endif

#endif
