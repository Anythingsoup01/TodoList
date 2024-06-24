#include "Application.h"

int main(int argc, char** argv)
{
	std::vector<std::string> tasks = OpenFile(tasks);

	int taskCount = (int)tasks.size();

	int option = -1;
	while (option != 0)
	{
		system("cls");
		print("---- TO DO LIST ----");
		print("1 - Add New Task");
		print("2 - View Tasks");
		print("3 - Delete Tasks");
		print("0 - Terminate Program");
		std::cin >> option;

		switch (option)
		{
		case 0:
		{
			SaveFile(tasks);
			break;
		}
		case 1:
			system("cls");
			tasks.push_back(AddTask(tasks, taskCount));
			taskCount = (int)tasks.size();
			break;
		case 2:
			system("cls");
			PrintTasks(tasks, taskCount);
			Sleep(5000);
			break;
		case 3:
			system("cls");
			taskCount = DeleteTask(tasks, taskCount);
			break;
		}
	}

	return 0;
}
