/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Copyright 2004-present Facebook. All Rights Reserved.
// -*- c++ -*-

#include "IndexBinaryFromFloat_c.h"
#include <faiss/IndexBinaryFromFloat.h>
#include "macros_impl.h"

extern "C" {

using faiss::Index;
using faiss::IndexBinaryFromFloat;

DEFINE_DESTRUCTOR(IndexBinaryFromFloat)
DEFINE_INDEX_BINARY_DOWNCAST(IndexBinaryFromFloat)

int faiss_IndexBinaryFromFloat_new(
        FaissIndexBinary** p_index,
        FaissIndex* index) {
    try {
        auto index_ = new IndexBinaryFromFloat(reinterpret_cast<Index*>(index));
        *p_index = reinterpret_cast<FaissIndexBinary*>(index_);
    }
    CATCH_AND_HANDLE
}

DEFINE_GETTER_PERMISSIVE(IndexBinaryFromFloat, FaissIndex*, index)

DEFINE_GETTER(IndexBinaryFromFloat, bool, own_fields)
DEFINE_SETTER(IndexBinaryFromFloat, bool, own_fields)

}
