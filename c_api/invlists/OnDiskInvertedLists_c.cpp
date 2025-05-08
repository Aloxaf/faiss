/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c -*-

#include "OnDiskInvertedLists_c.h"
#include <faiss/invlists/OnDiskInvertedLists.h>
#include "../macros_impl.h"

extern "C" {

using faiss::InvertedLists;
using faiss::OnDiskInvertedLists;

DEFINE_DESTRUCTOR(OnDiskInvertedLists)
DEFINE_DESTRUCTOR(InvertedLists)

const char* faiss_OnDiskInvertedLists_filename(
        const FaissOnDiskInvertedLists* invlists) {
    return reinterpret_cast<const OnDiskInvertedLists*>(invlists)
            ->filename.c_str();
}

void faiss_OnDiskInvertedLists_set_filename(
        FaissOnDiskInvertedLists* invlists,
        const char* filename) {
    reinterpret_cast<OnDiskInvertedLists*>(invlists)->filename = filename;
}

int faiss_OnDiskInvertedLists_new(
        FaissOnDiskInvertedLists** invlists,
        size_t nlist,
        size_t code_size,
        const char* filename) {
    try {
        OnDiskInvertedLists* invlists_ =
                new OnDiskInvertedLists(nlist, code_size, filename);
        *invlists = reinterpret_cast<FaissOnDiskInvertedLists*>(invlists_);
    }
    CATCH_AND_HANDLE
}

int faiss_OnDiskInvertedLists_merge_from_multiple(
        FaissOnDiskInvertedLists* invlists,
        const FaissInvertedLists** ils,
        int n_il,
        int shift_ids,
        int verbose) {
    try {
        const InvertedLists** ils_ =
                reinterpret_cast<const InvertedLists**>(ils);
        return reinterpret_cast<OnDiskInvertedLists*>(invlists)
                ->merge_from_multiple(ils_, n_il, shift_ids, verbose);
    }
    CATCH_AND_HANDLE
}
}
