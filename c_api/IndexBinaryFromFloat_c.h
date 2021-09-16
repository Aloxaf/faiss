/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Copyright 2004-present Facebook. All Rights Reserved.
// -*- c++ -*-

#ifndef FAISS_INDEX_BINARY_FROM_FLOAT_C_H
#define FAISS_INDEX_BINARY_FROM_FLOAT_C_H

#include "IndexBinary_c.h"
#include "faiss_c.h"

#ifdef __cplusplus
extern "C" {
#endif

FAISS_DECLARE_CLASS_INHERITED(IndexBinaryFromFloat, IndexBinary)
FAISS_DECLARE_INDEX_BINARY_DOWNCAST(IndexBinaryFromFloat)
FAISS_DECLARE_DESTRUCTOR(IndexBinaryFromFloat)

FAISS_DECLARE_GETTER(IndexBinaryFromFloat, FaissIndex*, index);
FAISS_DECLARE_GETTER_SETTER(IndexBinaryFromFloat, bool, own_fields)

int faiss_IndexBinaryFromFloat_new(FaissIndexBinary** p_index, FaissIndex* index);

#ifdef __cplusplus
}
#endif

#endif
