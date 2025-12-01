#include "protein_translation.hpp"

namespace protein_translation
{

Protein transateToProtein(Codon codon)
{
    if (codon == "AUG") return "Methionine";
    if (codon == "UUU") return "Phenylalanine";
    if (codon == "UUC") return "Phenylalanine";
    if (codon == "UUA") return "Leucine";
    if (codon == "UUG") return "Leucine";
    if (codon == "UCU") return "Serine";
    if (codon == "UCC") return "Serine";
    if (codon == "UCA") return "Serine";
    if (codon == "UCG") return "Serine";
    if (codon == "UAU") return "Tyrosine";
    if (codon == "UAC") return "Tyrosine";
    if (codon == "UGU") return "Cysteine";
    if (codon == "UGC") return "Cysteine";
    if (codon == "UGG") return "Tryptophan";

    if (codon == "UAA") return "STOP";
    if (codon == "UAG") return "STOP";
    if (codon == "UGA") return "STOP";

    return "";
}

Proteins proteins(Rna rna)
{
    Proteins proteins;

    const auto codonLenght = 3;
    auto currentNucleotide = 0;

    while(currentNucleotide < rna.size())
    {
        Codon codon = rna.substr(currentNucleotide, codonLenght);
        currentNucleotide += codonLenght;

        Protein protein = transateToProtein(codon);
        if (protein == "STOP") break;
        else proteins.push_back(protein);
    }

    return proteins;
}

}