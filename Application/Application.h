#pragma once
#include <fstream> 
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#define print(...) std::cout << __VA_ARGS__ << std::endl

std::string AddTask(std::vector<std::string> tasks)
{
	system("cls");
	std::string text;
	print("Enter A New Task: ");
	std::cin.ignore();
	std::getline(std::cin, text);
	return text;
}

bool PrintTasks(std::vector<std::string> tasks)
{
	system("cls");
	if ((int)tasks.size() > 0) {
		print("Tasks To Do");
		print("----------------------");
		int s = 0;
		for (auto i : tasks)
		{
			s++;
			print("Task: " << s << " : " << i);
		}
		print("----------------------");
	}
	else
	{
		print("You currently have no Tasks");
		return false;
	}
	return true;
}

std::vector<std::string> DeleteTask(std::vector<std::string> tasks)
{
	if (!PrintTasks(tasks))
	{
		Sleep(2500);
		return tasks;
	}
	int input = 0;
	print("Enter a task to delete: #");
	std::cin >> input;

	if (input < 0 || input > 9)
	{
		print("Invalid Task ID!");
		return tasks;
	}
	int s = 0;

	for (auto i : tasks)
	{
		if (s == input - 1)
		{
			auto it = std::find(tasks.begin(), tasks.end(), i);
			if (it != tasks.end()) {
				tasks.erase(it);
			}
		}
		s++;
	}

	return tasks;
}

void SaveFile(std::vector<std::string> tasks)
{
	int size = sizeof(tasks) / sizeof(tasks.size());
	std::ofstream outfile("tasks.txt");
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file for writing.\n";
		return;
	}
	int s = 0;
	for (auto i : tasks)
	{
		outfile << i << " ";
		s++;
	}
	outfile.close();
}

std::vector<std::string> OpenFile()
{
	std::vector<std::string> tasks;

	std::ifstream infile("tasks.txt");

	if (!infile.is_open())
	{
		return std::vector<std::string>();
	}

	std::string str;
	while (infile >> str)
		tasks.push_back(str);

	infile.close();
	return tasks;
}
