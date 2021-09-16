/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Copyright 2004-present Facebook. All Rights Reserved.
// -*- c++ -*-

#ifndef FAISS_INDEX_BINARY_FLAT_C_H
#define FAISS_INDEX_BINARY_FLAT_C_H

#include "IndexBinary_c.h"
#include "faiss_c.h"

#ifdef __cplusplus
extern "C" {
#endif

FAISS_DECLARE_CLASS_INHERITED(IndexBinaryFlat, IndexBinary)
FAISS_DECLARE_INDEX_BINARY_DOWNCAST(IndexBinaryFlat)
FAISS_DECLARE_DESTRUCTOR(IndexBinaryFlat)

int faiss_IndexBinaryFlat_new(FaissIndexBinary** p_index, idx_t d);

void faiss_IndexBinaryFlat_xb(FaissIndexBinary* index, uint8_t** p_xb, size_t* p_size);

FAISS_DECLARE_GETTER_SETTER(IndexBinaryFlat, bool, use_heap);
FAISS_DECLARE_GETTER_SETTER(IndexBinaryFlat, idx_t, query_batch_size);

#ifdef __cplusplus
}
#endif

#endif
