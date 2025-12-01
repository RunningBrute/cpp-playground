#pragma once

#include <vector>
#include <string>
#include <algorithm>

namespace protein_translation
{

using Codon = std::string;
using Rna = std::string;
using Protein = std::string;
using Proteins = std::vector<Protein>;

Proteins proteins(Rna);

}  // namespace hello_world