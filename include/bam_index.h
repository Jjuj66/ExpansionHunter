//
// Expansion Hunter
// Copyright (c) 2016 Illumina, Inc.
//
// Author: Egor Dolzhenko <edolzhenko@illumina.com>,
//         Mitch Bekritsky <mbekritsky@illumina.com>, Richard Shaw
// Concept: Michael Eberle <meberle@illumina.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef INCLUDE_BAM_INDEX_H_
#define INCLUDE_BAM_INDEX_H_

#include <string>
#include <vector>

#include "htslib/hts.h"

/*****************************************************************************/

class BamIndex {
 public:
  BamIndex(const std::string& bam_path);
  ~BamIndex();

  bool GetChrReadCounts(std::vector<std::string>& chrom_names,
                        std::vector<size_t>& chrom_lens,
                        std::vector<size_t>& mapped_read_counts,
                        std::vector<size_t>& unmapped_read_counts) const;

 private:
  htsFile* hts_file_ptr_;
  std::string bam_path_;
};

/*****************************************************************************/

#endif  // INCLUDE_BAM_INDEX_H_
