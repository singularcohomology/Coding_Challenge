#ifndef CODING_CHALLENGE_H
#define CODING_CHALLENGE_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

enum QNA_MESSAGE
{
	TOO_LONG,
	WRONG_FORMAT,
	EMPTY,
	OK
};

class Coding_Challenge
{
private:
	std::unordered_map<std::string, std::unordered_set<std::string>> questions_and_answers;
public:
	Coding_Challenge() {};
	Coding_Challenge(std::unordered_map<std::string, std::unordered_set<std::string>> QnA) : questions_and_answers(QnA) {};
	~Coding_Challenge() { questions_and_answers.clear(); };
	void start_quiz();
	QNA_MESSAGE add_question_and_answers(const std::string& input = "");
	std::unordered_set<std::string> ask_question(const std::string& input = "");
	bool is_question_stored(const std::string& question) { return questions_and_answers.find(question) != questions_and_answers.end(); };
	bool find_answer_for_question(const std::string& question, const std::string& answer) { return questions_and_answers[question].find(answer) != questions_and_answers[question].end(); };
	const std::unordered_set<std::string>& get_answers_from_question(const std::string& question) { return questions_and_answers[question]; };
	void set_questions_and_answers(const std::string& question, const std::unordered_set<std::string>& input) { questions_and_answers[question] = input; };
protected:
	void insert_questions_and_answers(std::string& question, std::unordered_set<std::string>& tokens) { questions_and_answers[question].insert(tokens.begin(), tokens.end()); };
};

#endif