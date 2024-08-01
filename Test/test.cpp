#include "pch.h"
#include "Coding_Challenge.hpp"
#include <gtest/gtest.h>
#include <sstream>

class Coding_Challenge_Test : public ::testing::Test {
protected:
    Coding_Challenge quiz;
};

TEST_F(Coding_Challenge_Test, AddQuestionAndAnswer)
{
    quiz.add_question_and_answers("What is the 1 singular homology group of S^1? \"The integers Z.\"");

    std::unordered_set<std::string> answers = quiz.get_answers_from_question("What is the 1 singular homology group of S^1");
    ASSERT_EQ(answers.size(), 1);
    ASSERT_EQ(quiz.find_answer_for_question("What is the 1 singular homology group of S^1", "The integers Z."), true);
}

TEST_F(Coding_Challenge_Test, AddTooLongQuestionAndAnswer)
{
    ASSERT_EQ(quiz.add_question_and_answers("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. "
        "Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, "
        "pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a,"
        "venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. "
        "Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius ...? \"The integers Z.\""),
        QNA_MESSAGE::TOO_LONG
        );
}

TEST_F(Coding_Challenge_Test, AddQuestionAndTooLongAnswer)
{
    ASSERT_EQ(quiz.add_question_and_answers("What is the Definition of the hawaiian earring? \"The Hawaiian earring H is the topological space defined by the union of circles in the Euclidean plane R^2 with center(1/n,0) and radius 1/n endowed with the subspace topology.\" \"More abstractly: the earring space can be described up to homeomorphism as the one-point compactification of a coproduct (in Top; a disjoint union space) of "
        "countably many open intervals (e.g. section 2.1 of (Cannon-Conner 2000)). This shows that the specific radii converging to zero (which was taken to be 1/2 n above) don’t actually matter. "
        "Equivalently, the earring space is homeomorphic to the one-point compactification of the product space NxR, where the space of real numbers R"
        "has the Euclidean topology and that of natural numbers N has the discrete topology.\""), QNA_MESSAGE::TOO_LONG);
}

TEST_F(Coding_Challenge_Test, AskStoredQuestion)
{
    quiz.set_questions_and_answers("What is the 1 singular homology group of S^1", { "The integers Z." });

    std::unordered_set<std::string> output = quiz.ask_question("What is the 1 singular homology group of S^1?");

    ASSERT_EQ(*output.begin(), "The integers Z.");
}

TEST_F(Coding_Challenge_Test, AskNonStoredQuestion)
{
    std::unordered_set<std::string> output = quiz.ask_question("What is the meaning of life?");

    ASSERT_EQ(*output.begin(), "The answer to life, universe and everything is 42.\n");
}

TEST_F(Coding_Challenge_Test, AskTooLongQuestion)
{
    std::unordered_set<std::string> output = quiz.ask_question("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. "
        "Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, "
        "pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a,"
        "venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. "
        "Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius ...?");

    ASSERT_EQ(output.empty(), true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}