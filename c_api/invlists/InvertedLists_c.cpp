/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c++ -*-

#include "InvertedLists_c.h"
#include <faiss/invlists/InvertedLists.h>
#include "../macros_impl.h"

using faiss::ArrayInvertedLists;
using faiss::HStackInvertedLists;
using faiss::InvertedLists;
using faiss::InvertedListsIterator;
using faiss::MaskedInvertedLists;
using faiss::ReadOnlyInvertedLists;
using faiss::SliceInvertedLists;
using faiss::StopWordsInvertedLists;
using faiss::VStackInvertedLists;

// InvertedLists

DEFINE_DESTRUCTOR(InvertedLists)

DEFINE_DESTRUCTOR(ReadOnlyInvertedLists)
DEFINE_DESTRUCTOR(HStackInvertedLists)
DEFINE_DESTRUCTOR(SliceInvertedLists)
DEFINE_DESTRUCTOR(VStackInvertedLists)
DEFINE_DESTRUCTOR(MaskedInvertedLists)
DEFINE_DESTRUCTOR(StopWordsInvertedLists)
DEFINE_DESTRUCTOR(ArrayInvertedLists)

// ArrayInvertedLists

int faiss_ArrayInvertedLists_new(
        FaissArrayInvertedLists** p_invlists,
        size_t nlist,
        size_t code_size) {
    try {
        *p_invlists = reinterpret_cast<FaissArrayInvertedLists*>(
                new ArrayInvertedLists(nlist, code_size));
    }
    CATCH_AND_HANDLE
}

// HStackInvertedLists

int faiss_HStackInvertedLists_new(
        FaissHStackInvertedLists** p_invlists,
        int nil,
        const FaissInvertedLists** ils) {
    try {
        const InvertedLists** ils_ =
                reinterpret_cast<const InvertedLists**>(ils);
        *p_invlists = reinterpret_cast<FaissHStackInvertedLists*>(
                new HStackInvertedLists(nil, ils_));
    }
    CATCH_AND_HANDLE
}

// SliceInvertedLists

int faiss_SliceInvertedLists_new(
        FaissSliceInvertedLists** p_invlists,
        const FaissInvertedLists* il,
        idx_t i0,
        idx_t i1) {
    try {
        *p_invlists = reinterpret_cast<FaissSliceInvertedLists*>(
                new SliceInvertedLists(
                        reinterpret_cast<const InvertedLists*>(il), i0, i1));
    }
    CATCH_AND_HANDLE
}

// VStackInvertedLists

int faiss_VStackInvertedLists_new(
        FaissVStackInvertedLists** p_invlists,
        int nil,
        const FaissInvertedLists** ils) {
    try {
        const InvertedLists** ils_ =
                reinterpret_cast<const InvertedLists**>(ils);
        *p_invlists = reinterpret_cast<FaissVStackInvertedLists*>(
                new VStackInvertedLists(nil, ils_));
    }
    CATCH_AND_HANDLE
}

// MaskedInvertedLists

int faiss_MaskedInvertedLists_new(
        FaissMaskedInvertedLists** p_invlists,
        const FaissInvertedLists* il0,
        const FaissInvertedLists* il1) {
    try {
        *p_invlists = reinterpret_cast<FaissMaskedInvertedLists*>(
                new MaskedInvertedLists(
                        reinterpret_cast<const InvertedLists*>(il0),
                        reinterpret_cast<const InvertedLists*>(il1)));
    }
    CATCH_AND_HANDLE
}

// StopWordsInvertedLists

int faiss_StopWordsInvertedLists_new(
        FaissStopWordsInvertedLists** p_invlists,
        const FaissInvertedLists* il,
        size_t maxsize) {
    try {
        *p_invlists = reinterpret_cast<FaissStopWordsInvertedLists*>(
                new StopWordsInvertedLists(
                        reinterpret_cast<const InvertedLists*>(il), maxsize));
    }
    CATCH_AND_HANDLE
}
