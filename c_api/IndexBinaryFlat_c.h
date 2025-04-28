/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c -*-

#ifndef FAISS_INDEX_BINARY_FLAT_C_H
#define FAISS_INDEX_BINARY_FLAT_C_H

#include "IndexBinary_c.h"
#include "faiss_c.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Index that stores the full binary vectors and performs exhaustive search */
FAISS_DECLARE_CLASS(IndexBinaryFlat)
FAISS_DECLARE_DESTRUCTOR(IndexBinaryFlat)
FAISS_DECLARE_INDEX_BINARY_DOWNCAST(IndexBinaryFlat)

/// Select between using a heap or counting to select the k smallest values when
/// scanning
FAISS_DECLARE_GETTER_SETTER(IndexBinaryFlat, int, use_heap)

/// Batch size for queries
FAISS_DECLARE_GETTER_SETTER(IndexBinaryFlat, size_t, query_batch_size)

/** Build a binary flat index
 *
 * @param d dimensionality of the vectors
 */
int faiss_IndexBinaryFlat_new(FaissIndexBinaryFlat** p_index, int d);

/** Get a pointer to the index's internal vector storage
 *
 * @param index opaque pointer to index object
 * @param xb_out output pointer to the vector data (size ntotal * d / 8)
 */
int faiss_IndexBinaryFlat_xb(
        const FaissIndexBinaryFlat* index,
        uint8_t** xb_out);

#ifdef __cplusplus
}
#endif

#endif