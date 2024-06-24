#include "Application.h"

int main(int argc, char** argv)
{
	std::vector<std::string> tasks = OpenFile();

	int opt = -1;
	while (opt != 0)
	{
		system("cls");
		print("---- TO DO LIST ----");
		print("1 - Add New Task");
		print("2 - View Tasks");
		print("3 - Delete Tasks");
		print("0 - Terminate Program");
		std::cin >> opt;

		switch (opt)
		{
		case 0:
		{
			SaveFile(tasks);
			break;
		}
		case 1:
		{
			tasks.push_back(AddTask(tasks));
			break;
		}
		case 2:
		{
			PrintTasks(tasks);
			Sleep(2500);
			break;
		}
		case 3:
			tasks = DeleteTask(tasks);
			break;
		}
	}
	return 0;
}