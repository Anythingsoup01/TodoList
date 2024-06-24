#pragma once
#include <fstream> 
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#define print(...) std::cout << __VA_ARGS__ << std::endl

std::string AddTask(std::vector<std::string> tasks, int taskCount)
{
	std::string text;
	if (taskCount > 9)
	{
		print("--- TASK LIST IS FULL ---");
		Sleep(1000);
		system("cls");
		return std::string();
	}
	print("Enter A New Task: ");
	std::cin.ignore();
	std::getline(std::cin, text);
	return text;
}

bool PrintTasks(std::vector<std::string> tasks, int taskCount)
{
	if (taskCount > 0) {
		print("Tasks To Do");
		print("----------------------");
		int s = 0;
		for (auto i : tasks)
		{
			s++;
			print("Task: "<<s<< " : " << i);
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

int DeleteTask(std::vector<std::string> tasks, int taskCount)
{
	if (!PrintTasks(tasks, taskCount))
	{
		Sleep(2500);
		return taskCount;
	}
	int input = 0;
	print("Enter a task to delete: #");
	std::cin >> input;

	if (input < 0 || input > 9)
	{
		print("Invalid Task ID!");
		return taskCount;
	}
	for (int i = input - 1; i < taskCount; i++)
	{
		tasks[i] = tasks[i + 1];
	}
	return taskCount - 1;
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

std::vector<std::string> OpenFile(std::vector<std::string> tasks) {

	int size = sizeof(tasks) / sizeof(tasks[0]);
	// Opening the file in read mode 

	std::ifstream infile("tasks.txt");

	if (!infile.is_open())
	{
		return std::vector<std::string>();
	}

	// Reading the array elements from the file 
	std::string str;
	while (infile >> str)
		tasks.push_back(str);

	// Closing the file 
	infile.close();
	return tasks;
}