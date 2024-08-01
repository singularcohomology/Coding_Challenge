// Coding_Challenge.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "Coding_Challenge.hpp"

#include <regex>

using namespace std;

#define MAX_LENGTH 255

QNA_MESSAGE Coding_Challenge::add_question_and_answers(const string& input)
{
    std::string QnA;
    std::unordered_set<std::string> tokens;
    std::string question;
    bool answer_too_long = false;

    while (true)
    {
        if (input.empty())
        {
            cout << "Add your question and answers: " << endl;
            std::getline(cin, QnA);
        }
        else
        {
            QnA = input;
        }
        // Find '?' separator.
        size_t question_mark = QnA.find_first_of("?");
        // If there is no question mark the input has an invalid format.
        if (question_mark == string::npos)
        {
            cout << "Invalid format. Make sure to use '?' as the separator between question and answers.\n";
            return QNA_MESSAGE::WRONG_FORMAT;
        }
        // Check if question has less than 255 byte length.
        if (question_mark > MAX_LENGTH)
        {
            cout << "Question exceeds maximum length of " << MAX_LENGTH << " characters.\n";
            return QNA_MESSAGE::TOO_LONG;
        }
        question = std::string(QnA.substr(0, question_mark));

        // Check for potential answers using the format "<answer1>" "<answer2>" ...
        unique_ptr<std::string> answers(new std::string(QnA.substr(question_mark)));
        regex reg{ R"x("([^"]*)")x" };

        // Filter out empty answers and answers with a total length > 255 characters.
        std::remove_copy_if(sregex_token_iterator(answers->begin(), answers->end(), reg, { 1, 2 }), sregex_token_iterator(),
            std::inserter(tokens, tokens.begin()),
            [&answer_too_long](std::string const& s) { 
                answer_too_long |= s.length() > MAX_LENGTH;
                return s.empty() || s.length() > MAX_LENGTH; 
            }
        );

        // We are storing all the answers that are not too long.
        if (tokens.empty())
        {
            cout << "Answers were either empty or too long. An answer can consist of at maximum 255 characters." << endl;
            return QNA_MESSAGE::EMPTY;
        }
        break;
    }
    //const shared_ptr<unordered_set<std::string>> answers_token(new unordered_set<std::string>(tokens.begin(), tokens.end()));
    //If the question is already stored ask if the answers should get discarded or the new answers should be added to them.
    if (is_question_stored(question))
    {
        unsigned short option;
        cout << "Question is already stored. Do you want to discard the new answers, overwrite the old answers or append them?\n";
        cout << "1.Discard\n";
        cout << "2.Overwrite\n";
        cout << "3.Append\n";
        cin >> option;
        switch (option)
        {
        case 1:
            return QNA_MESSAGE::OK;
        case 2:
        {
            set_questions_and_answers(question, tokens);
            break;
        }
        case 3:
            insert_questions_and_answers(question, tokens);
            break;
        }
    } 
    else
    {
        set_questions_and_answers(question, tokens);
    }
    return answer_too_long ? QNA_MESSAGE::TOO_LONG : QNA_MESSAGE::OK;
}

unordered_set<string> Coding_Challenge::ask_question(const string& input)
{
    bool found = false;
    std::string question;

    // Check input format and remove question mark from question
    if (input.empty())
    {
        while (true)
        {
            cout << "State your question: " << '\n';
            getline(cin, question);

            if (question.find_first_of("?") == std::string::npos || question.length() - 1 > MAX_LENGTH)
            {
                // We saved the question without a question mark '?'.
                cout << "Invalid format. Make sure to use '?' for a question and not exceed the 255 character limit.\n";
                continue;
            }
            break;
        }

        question = question.substr(0, question.length() - 1);
    }
    else
    {
        if (input.find_first_of("?") == std::string::npos || input.length() - 1 > MAX_LENGTH)
        {
            cout << "Invalid format. Make sure to use '?' for a question and not exceed the 255 character limit.\n";
            return {};
        }
        question = input.substr(0, input.length() - 1);
    }
    
    // Try to find question and output every answer in a separate line.
    if (is_question_stored(question))
    {
        unordered_set<string> answers = get_answers_from_question(question);
        for (const auto& answer : answers)
        {
            cout << answer << '\n';
        }
        return answers;
    }
    else
    {
        // If the question was not found, output standard answer.
        cout << "The answer to life, universe and everything is 42.\n";
        return std::unordered_set<std::string> {"The answer to life, universe and everything is 42.\n"};
    }
}

void Coding_Challenge::start_quiz()
{
    int choice;
    std::string input;
    
    while (true)
    {
        cout << "1. Ask a question\n";
        cout << "2. Add a question and answers\n";
        cout << "3. Exit\n";
        cout << "Enter your option: ";
        getline(cin, input);

        choice = atoi(input.c_str());

        if (choice == 0 || choice > 3)
        {
            cout << "Invalid input." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            ask_question();
            break;
        case 2:
            add_question_and_answers();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Please choose 1, 2, or 3.\n";
        }
    }
}