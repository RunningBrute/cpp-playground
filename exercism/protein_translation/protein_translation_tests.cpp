#include <gtest/gtest.h>
#include "protein_translation.hpp"

using namespace std;

TEST(ProteinTranslation, Methionine_RNA_sequence)
{
    EXPECT_TRUE(vector<string>{"Methionine"} == protein_translation::proteins("AUG"));
}

TEST(ProteinTranslation, Phenylalanine_RNA_sequence_1)
{
    EXPECT_TRUE(vector<string>{"Phenylalanine"} == protein_translation::proteins("UUU"));
}

TEST(ProteinTranslation, Phenylalanine_RNA_sequence_2)
{
    EXPECT_TRUE(vector<string>{"Phenylalanine"} == protein_translation::proteins("UUC"));
}

TEST(ProteinTranslation, Leucine_RNA_sequence_1)
{
    EXPECT_TRUE(vector<string>{"Leucine"} == protein_translation::proteins("UUA"));
}

TEST(ProteinTranslation, Leucine_RNA_sequence_2)
{
    EXPECT_TRUE(vector<string>{"Leucine"} == protein_translation::proteins("UUG"));
}

TEST(ProteinTranslation, Serine_RNA_sequence_1)
{
    EXPECT_TRUE(vector<string>{"Serine"} == protein_translation::proteins("UCU"));
}

TEST(ProteinTranslation, Serine_RNA_sequence_2)
{
    EXPECT_TRUE(vector<string>{"Serine"} == protein_translation::proteins("UCC"));
}

TEST(ProteinTranslation, Serine_RNA_sequence_3)
{
    EXPECT_TRUE(vector<string>{"Serine"} == protein_translation::proteins("UCA"));
}

TEST(ProteinTranslation, Serine_RNA_sequence_4)
{
    EXPECT_TRUE(vector<string>{"Serine"} == protein_translation::proteins("UCG"));
}

TEST(ProteinTranslation, Tyrosine_RNA_sequence_1)
{
    EXPECT_TRUE(vector<string>{"Tyrosine"} == protein_translation::proteins("UAU"));
}

TEST(ProteinTranslation, Tyrosine_RNA_sequence_2)
{
    EXPECT_TRUE(vector<string>{"Tyrosine"} == protein_translation::proteins("UAC"));
}

TEST(ProteinTranslation, Cysteine_RNA_sequence_1)
{
    vector<string> expected{"Cysteine"};
    EXPECT_TRUE(expected == protein_translation::proteins("UGU"));
}

TEST(ProteinTranslation, Cysteine_RNA_sequence_2)
{
    vector<string> expected{"Cysteine"};
    EXPECT_TRUE(expected == protein_translation::proteins("UGC"));
}

TEST(ProteinTranslation, Tryptophan_RNA_sequence)
{
    vector<string> expected{"Tryptophan"};
    EXPECT_TRUE(expected == protein_translation::proteins("UGG"));
}

TEST(ProteinTranslation, STOP_codon_RNA_sequence_1)
{
    EXPECT_TRUE(vector<string>{} == protein_translation::proteins("UAA"));
}

TEST(ProteinTranslation, STOP_codon_RNA_sequence_2)
{
    EXPECT_TRUE(vector<string>{} == protein_translation::proteins("UAG"));
}

TEST(ProteinTranslation, STOP_codon_RNA_sequence_3)
{
    EXPECT_TRUE(vector<string>{} == protein_translation::proteins("UGA"));
}

TEST(ProteinTranslation, Translate_RNA_strand_into_correct_protein_list)
{
    vector<string> expected{"Methionine","Phenylalanine","Tryptophan"};
    EXPECT_TRUE(expected == protein_translation::proteins("AUGUUUUGG"));
}

TEST(ProteinTranslation, Translation_stops_if_STOP_codon_at_beginning_of_sequence)
{
    EXPECT_TRUE(vector<string>{} == protein_translation::proteins("UAGUGG"));
}

TEST(ProteinTranslation, Translation_stops_if_STOP_codon_at_end_of_two_codon_sequence)
{
    vector<string> expected{"Tryptophan"};
    EXPECT_TRUE(expected == protein_translation::proteins("UGGUAG"));
}

TEST(ProteinTranslation, Translation_stops_if_STOP_codon_at_end_of_three_codon_sequence)
{
    vector<string> expected{"Methionine","Phenylalanine"};
    EXPECT_TRUE(expected == protein_translation::proteins("AUGUUUUAA"));
}

TEST(ProteinTranslation, Translation_stops_if_STOP_codon_in_middle_of_three_codon_sequence)
{
    vector<string> expected{"Tryptophan"};
    EXPECT_TRUE(expected == protein_translation::proteins("UGGUAGUGG"));
}

TEST(ProteinTranslation, Translation_stops_if_STOP_codon_in_middle_of_six_codon_sequence)
{
    vector<string> expected{"Tryptophan","Cysteine","Tyrosine"};
    EXPECT_TRUE(expected == protein_translation::proteins("UGGUGUUAUUAAUGGUUU"));
}