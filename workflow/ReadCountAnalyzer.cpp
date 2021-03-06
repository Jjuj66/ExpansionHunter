//
// Expansion Hunter
// Copyright 2016-2019 Illumina, Inc.
// All rights reserved.
//
// Author: Egor Dolzhenko <edolzhenko@illumina.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//

#include "workflow/ReadCountAnalyzer.hh"

#include "common/Common.hh"

using std::shared_ptr;
using std::vector;

namespace ehunter
{

static AlleleCount determineExpectedAlleleCount(ContigCopyNumber copyNumber, Sex sex)
{
    switch (copyNumber)
    {
    case ContigCopyNumber::kTwoInFemaleTwoInMale:
        return AlleleCount::kTwo;
    case ContigCopyNumber::kTwoInFemaleOneInMale:
        return (sex == Sex::kFemale ? AlleleCount::kTwo : AlleleCount::kOne);
    case ContigCopyNumber::kZeroInFemaleOneInMale:
        return (sex == Sex::kFemale ? AlleleCount::kZero : AlleleCount::kOne);
    }

    return AlleleCount::kTwo; // To remove spurious control reaches end of non-void function warning
}

ReadCountAnalyzer::ReadCountAnalyzer(ContigCopyNumber contigCopyNumber, std::shared_ptr<ReadCounter> counter)
    : contigCopyNumber_(contigCopyNumber)
    , counter_(std::move(counter))
{
}

vector<shared_ptr<Feature>> ReadCountAnalyzer::features() { return { counter_ }; }

LocusStats ReadCountAnalyzer::estimate(Sex sampleSex) const
{
    const int readLength = counter_->getReadLength();
    const double depth = counter_->getDepth();

    AlleleCount alleleCount = determineExpectedAlleleCount(contigCopyNumber_, sampleSex);

    return { alleleCount, readLength, depth };
}

}
