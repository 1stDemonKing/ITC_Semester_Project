#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	char choice{};
	int noOfProb = 0;
	int n1 = 0;
	int n2 = 0;
	int op = 0;
	int eMinRange = 0;
	int eMaxRange = 0;
	int ans = 0;
	int score = 0;
	int totalScore = 0;
	srand(time(0));
	do
	{
		const int operations = 4;
		const int levels = 3;
		int operation[operations]{ 0 };
		int correct[operations]{ 0 };
		bool level[levels]{ false };
		cout << "Please make a selection from the following " << endl;
		cout << "P: Practice Math" << endl;
		cout << "S: Show Score" << endl;
		cout << "Q: Quit" << endl;
		cout << "What do you want to do: ";
		cin >> choice;
		while (choice != 'P' && choice != 'p' &&
			choice != 'S' && choice != 's' &&
			choice != 'q' && choice != 'Q')
		{
			cout << "Invalid!\nEnter Again: ";
			cin >> choice;
		}
		if (choice == 'P' || choice=='p')
		{
			cout << "What difficult level do you want: "<<endl;
			cout << "E: Easy" << endl;
			cout << "M: Medium" << endl;
			cout << "H: Hard" << endl;;
			cout << "Enter difficult level:";
			cin >> choice;
			while (choice != 'e' && choice != 'E' &&
				choice != 'm' && choice != 'M' &&
				choice != 'h' && choice != 'H')
			{
				cout << "Invalid!\nEnter Again: ";
				cin >> choice;
			}
			cout << "How many problems do you want? ";
			cin >> noOfProb;
			if (choice == 'e' || choice == 'E')
			{
				eMinRange = -10;
				eMaxRange = 10;
				totalScore = 2 * noOfProb;
				level[0] = true;
			}
			else if (choice == 'e' || choice == 'E')
			{
				eMinRange = -50;
				eMaxRange = 50;
				totalScore = 4 * noOfProb;
				level[1] = true;
			}
			else
			{
				eMinRange = -100;
				eMaxRange = 100;
				totalScore = 5 * noOfProb;
				level[2] = true;
			}
				for (int x = 0; x < noOfProb; x++)
				{
					n1 = eMinRange + rand() % (eMaxRange - eMinRange + 1);
					n2 = eMinRange + rand() % (eMaxRange - eMinRange + 1);
					op = rand() % 4;
					//cout << op << endl;
					if (!op)
					{
						while(!n2)
							eMinRange = rand() % (eMaxRange - eMinRange + 1);
						operation[op]++;
						cout << "What is " << n1 << '/' << n2 << " ?";
						cin >> ans;
						if (n1 / n2 == ans)
						{
							cout << "Correct great job" << endl;
							if (level[0])
								correct[op] += 2;
							else if (level[1])
								correct[op] += 4;
							else
								correct[op] += 5;
						}
						else
							cout << "Sorry, that's incorrect, the answer is " << n1 / n2 << '.' << endl;
					}
					else if (op == 1)
					{
						operation[op]++;
						cout << "What is " << n1 << '*' << n2 << " ?";
						cin >> ans;
						if (n1 * n2 == ans)
						{
							cout << "Correct great job" << endl;
							if (level[0])
								correct[op] += 2;
							else if (level[1])
								correct[op] += 4;
							else
								correct[op] += 5;
						}
						else
							cout << "Sorry, that's incorrect, the answer is " << n1 * n2 << '.' << endl;
					}
					else if (op == 2)
					{
						operation[op]++;
						cout << "What is " << n1 << '+' << n2 << " ?";
						cin >> ans;
						if (n1 + n2 == ans)
						{
							cout << "Correct great job" << endl;
							if (level[0])
								correct[op] += 2;
							else if (level[1])
								correct[op] += 4;
							else
								correct[op] += 5;
						}
						else
							cout << "Sorry, that's incorrect, the answer is " << n1 + n2 << '.' << endl;
					}
					else
					{
						operation[op]++;
						cout << "What is " << n1 << '-' << n2 << " ?";
						cin >> ans;
						if (n1 - n2 == ans)
						{
							cout << "Correct great job" << endl;
							if (level[0])
								correct[op] += 2;
							else if (level[1])
								correct[op] += 4;
							else
								correct[op] += 5;
						}
						else
							cout << "Sorry, that's incorrect, the answer is " << n1 - n2 << '.' << endl;
					}
				}
				
				for (int x = 0; x < noOfProb; x++)
					score += correct[x];
				int temp = 0;
				if (level[0])
					temp = 2;
				else if (level[1])
					temp = 4;
				else if (level[2])
					temp = 5;
				for (int x = 0; x < operations; x++)
					correct[x] /= temp;
				int tempScore = totalScore/temp;
				cout << "Your Score is " << score << '/' << totalScore << endl;
				cout << "Addition\t" << "Subtraction\t" << "Multiplcation\t" << "Division" << endl;
				cout << correct[2] << '/' << operation[2] << "\t\t" << correct[3] << '/' << operation[3] << "\t\t" << correct[1] << '/' << operation[1] << "\t\t" << correct[0] << '/' << operation[0] << "\t\t" << endl;
				int maxIncorrect = INT_MIN;
				int incorrect[operations]{ 0 };
				//for (int x = 0; x < operations; x++)
				//	incorrect[x] = operation[x] - correct[x];
				for (int x = 0; x < operations; x++)
					if (operation[x] - correct[x] > maxIncorrect)
						maxIncorrect = x;
				//cout << maxIncorrect << endl;
				/*for (int x = 0; x < operations; x++)
					cout << incorrect[x] << ' ';*/	
				if (!maxIncorrect)
					cout << "Need more practice with:\n" << "Division" << endl;
				else if (maxIncorrect==1)
					cout << "Need more practice with:\n" << "Multiplication" << endl;
				else if(maxIncorrect==2)
					cout << "Need more practice with:\n" << "Addition" << endl;
				else
					cout << "Need more practice with:\n" << "Subtraction" << endl;

		}

	} while (choice != 'Q' && choice != 'q');
}