#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
double indep[50]; //creating account
string fname[50], lname[50], id[50], acc[50], date[50], code[50], tempcode, iddd; // creating account
int num[50], maintaining[50]; //creating account

int dephistory[50], withhistory[50], allhistory[50], balance[50], ref[50], amnt[50], recipient, mark[50]; //transaction
string  type[50], transacdate[50], transacname[50]; //transaction

int choice, count = 0, check=0, accnum, accno = 20240011, x, y, c, s, deposit = 0, with = 0, all = 0, reference, space, idd;
double amount, withdraw, dep;
string last, first, spacing, n, Wcode;
char answer, notice;
bool loop = true, inloop = true; // controlling while loop

ofstream files("AccountSummary.txt");
ofstream per("AccountStatement.txt");
ofstream allacc("ReportAllAccount.txt");
	
	for (int x = 0; x < 50; x++) 
	{
  	  indep[x] = 0.00;
	}
	
	cout << "  BANKING SYSTEM\n";

	while (inloop)
	{
	
	cout << "\nTransactions: \n";
	cout << "1 - Create Account\n";
	cout << "2 - Deposit\n";
	cout << "3 - Withdrawal\n";
	cout << "4 - Transfer Money\n";
	cout << "5 - Check Balance\n";
	cout << "6 - Summary\n";
	cout << "7 - Reports per account\n";
	cout << "8 - Reports (all account)\n";
	cout << "9 - Exit\n\n";
	
	cout << "Choice between 1-9: ";
	cin >> choice;
	cout << "\n";
	switch (choice) {
		
		case 1: //create
			loop = true;

			cout << "Banking System\n\n";
			do
			{			
			cout << "-------------------------------------------------------------------------\n";													
			cout << "                               Type of Account                           \n";
			cout << "                    A1 - Savings with Booklet and ATM      \n";
			cout << "                       - 10,000 maintaning balance      \n";
			cout << "                       - -300 if the balance < 10,000 \n\n";
			cout << "-------------------------------------------------------------------------\n";	
			cout << "                    A2 - Savings with ATM only             \n";
			cout << "                       - 5,000 mainting balance         \n";
			cout << "                       - -300 if the balance < 5,000  \n\n";
			cout << "-------------------------------------------------------------------------\n";	
			cout << "                    A3 - Cash Card\n";
			cout << "                       - No maintaining balance\n";
			cout << "-------------------------------------------------------------------------\n\n";
			cout << " Account type   - ";
			cin >> acc[count];
			}
			while (acc[count] != "A1" && acc[count] != "A2" && acc[count] != "A3");
			cout << "  Last name     - ";
			cin.ignore();
			getline(cin,lname[count]);
			cout << "  First name    - ";
			getline(cin,fname[count]);
			cout << "\n---------------------------------------------------------------------------------\n";   										
			cout << "                                  ID TYPE                                        \n";
			cout << "        1 - Passport        4 - PRC ID           7 - Philippine National ID          \n";
			cout << "        2 - Voter's ID      5 - SSS card/UMID    8 - Driver's License                \n";
			cout << "        3 - Postal ID       6 - GSIS e-card      9 -  Others                         \n";
			cout << "---------------------------------------------------------------------------------\n\n";
			cout << "   ID type      - ";
			cin >> idd;
			
			switch (idd) {
				
				case 1:
					id[count] = "Passport";
					break;
					
				case 2:
					id[count] = "Voter's ID";
			 		break;
			 		
				case 3:
					id[count] = "Postal ID";
					break;
					
				case 4:
					id[count] = "PRC ID";
					break;
					
				case 5:
					id[count] = "SSS card/UMID";
					break;
					
				case 6:
					id[count] = "GSIS e-card";
					break;
					
				case 7:
					id[count] = "Philippine National ID";
					break;
					
				case 8:
					id[count] = "Driver's License";
					break;
				case 9:
					cout << "Please Specify the ID manually :";
					cin.ignore();
					getline(cin,iddd);
					id[count] = iddd;
					break;
			}
			while(loop)
			{
			cout << "Initial Deposit - ";
			cin >> dep; 
			indep[count] = indep[count] + dep;
			
			if (acc[count] == "A1")
			{
				if (indep[count] >= 10000)
				{
					loop = false;
				} 
				else
				{
					cout << "\nThe minimum initial deposit is Php 10,000\n\n";
					
				}
			}
			else if (acc[count] == "A2")
			{
				if (indep[count] >= 5000)
				{
					loop = false;
				}
				else
				{
					cout << "\nThe minimum initial deposit is Php 5,000\n\n";
					
				}
			} 
			else if (acc[count] == "A3")
			{
				loop = false;
			}
			
			
			}
			do
			{
			cout << "     Code       - ";
			cin >> tempcode;
			if (tempcode.length() == 4)
			{
				for (x = 0; x < tempcode.length(); x++)
				{
					if (tempcode[x] >= '0' && tempcode[x] <= '9')
					{
						code[count] = tempcode;
					}
				}
			}
			else
			{
				cout << "\nPlease enter 4-digit code!\n\n";
			}
			}
			while (tempcode.length() != 4);
			num[count] = accno;
			accno ++;
			
			cout << "\n---------------------------------------\n";
			cout << "         Account succesfully created     \n";
			cout << "Name                : " << fname[count] << " " << lname[count] << "\n";
			cout << "Account Number      : " << num[count] << "\n";
			cout << "ID Type             : " << id[count] << "\n";
			cout << "Initial Deposit     : " << indep[count] << "\n";
			
			if (acc[count] == "A1")
			{
				maintaining[count] = 10000;
				cout << "Account Type        : Savings with Booklet and ATM \n";
				cout << "Maintaining Balance : 10,000 \n";
				
			} 
			else if (acc[count] == "A2") 
			{
				maintaining[count] = 5000;
				cout << "Account Type        : Savings with ATM only \n";
				cout << "Maintaining Balance : 5,000 \n";
			}
			else
			{
				maintaining[count] = 0;
				cout << "Account Type        : Cash Card \n";
				cout << "No Maintaining Balance ";
			}
			cout << "\n---------------------------------------\n";
			date[count] = __DATE__;
			count++;
			
			break;
			
		case 2: //deposit
			loop = true;
			
			while (loop)
			{
			check = 0;
			cout << "          DEPOSIT     \n\n"; 
			cout << "Account number      : ";
			cin >> accnum;
			cout << "Amount to deposited : ";
			cin >> amount; // = 5000
			
			for (x=0; x < count; x++)
			{
				if(accnum == num[x]) 
				{
					indep[x] = indep[x] + amount; // current balance + deposit amount
					reference = indep[x];
					
					if (indep[x] > 100000 && indep[x] < 600000 )
					{
						reference = reference / 6;
					} 
					else if (indep[x] > 10000 && indep[x] < 100000 )
					{
						reference = 18762 + (reference / 5);
					}
					else if (indep[x] > 0 && indep[x] < 10000 )
					{
						reference = 13963 + reference;
					} 
					else 
					{
						reference = reference / 7;	
					}
					
					for (y = 0; y < all; y++)
					{
						if (reference == ref[y])
						{
							reference++;
						}
					}

					cout << "\n---------------------------------------\n";
					cout << "           Deposit Successful!\n";
					cout << "Name                : " << fname[x] << " " << lname[x] << "\n";
					cout << "Account Number      : " << num[x] << "\n";
					cout << "Reference No.       : " << reference << "\n";
					cout << "Amount deposited    : Php " << amount << "\n";
					cout << "Outstanding Balance : Php " << indep[x] << "\n";
					cout << "---------------------------------------\n\n";

					
					//deposits transaction history
					transacdate[all] = __DATE__ ;
					ref[all] = reference;
					amnt[all] = amount;
					balance[all] = indep[x];
					mark[all] = x;
					type[all] = "dep";
					
					all++;
					check++;
					loop = false;

				}	
			}	
			if(check == 0)
				{
				cout << "\n      No account information match\n";
				cout << "Please enter the correct account information \n\n";
				break;			
				}
			}
			
			break;
			
		case 3: //withdrawal
			loop = true;
			check = 0;
			
			while (loop)
			{
			cout << "         WITHDRAWAL     \n\n"; 
			cout << "Account number     : ";
			cin >> accnum;
			cout << "Amount to withdraw : ";
			cin >> withdraw;
			cout << "Code               : ";
			cin >> Wcode;
			
			for (x=0; x < count; x++)
			{
				if (accnum == num[x] && code[x] == Wcode)
				{
					if (indep[x] >= withdraw)
					{
						if (indep[x] - withdraw < maintaining[x])
						{
							cout << "   Notice: Withdrawing this amount may include a penalty fee.\n";
							cout << "Your account balance may fall below the maintaining balance.\n";
							cout << "A penalty fee of Php 300 will be applied if the balance goes below this limit.\n";
							cout << "Do you still want to continue with the withdrawal? (Y/N): ";
							cin >> notice;
							
							if (notice == 'Y' || notice == 'y')
							{
								indep[x] = indep[x] - withdraw;
								reference = indep[x];
						
								if (indep[x] > 100000 && indep[x] < 599999 )
								{
									reference = reference / 6;
								} 
								else if (indep[x] > 10000 && indep[x] < 100000 )
								{
									reference = 18762 + (reference / 5);
								}
								else if (indep[x] > 0 && indep[x] < 10000 )
								{
									reference = 13963 + reference;
								} 
								else 
								{
									reference = reference / 7;	
								}
						
								cout << "\n---------------------------------------\n";
								cout << "Withdrawal Successful!\n";
								cout << "Name              : " << fname[x] << " " << lname[x] << "\n";
								cout << "Account Number    : " << num[x] << "\n";
								cout << "Withdrawn Amount  : Php " << withdraw << "\n";
								cout << "Reference No.     : " << reference << "\n";
									
								if ( acc[x] == "A1" && indep[x] < 10000)
								{
									indep[x] -= 300;
									cout << "---------------------------------------\n\n";
									cout << "Penalty Applied     : Php 300.00\n";
									cout << "Outstanding Balance : Php " << indep[x] << "\n";
									cout << "---------------------------------------\n\n";
								} 
								else if ( acc[x] == "A2" && indep[x] < 5000)
								{
									indep[x] -= 300;
									cout << "---------------------------------------\n\n";
									cout << "Penalty Applied     : Php 300.00\n";
									cout << "Outstanding Balance : Php " << indep[x] << "\n";
									cout << "---------------------------------------\n\n";
								}
								else
								{
									cout << "---------------------------------------\n";
									cout << "Outstanding Balance : Php " << indep[x] << "\n";
									cout << "---------------------------------------\n\n";
								}
						
								//withdrawals transaction history
								transacdate[all] = __DATE__;
								ref[all] = reference;
								amnt[all] = withdraw;
								balance[all] = indep[x];
								mark[all] = x;
								type[all] = "with";
								all++;
								
								check++;
								loop = false;
							}
							else 
							{
								cout << "\n        Your available balance is Php " << indep[x] <<"\n";
								cout << "Please enter a smaller amount or deposit funds first.\n";
								loop = false;
							}
						}
						else
						{
							indep[x] = indep[x] - withdraw;
							reference = indep[x];
						
							if (indep[x] > 100000 && indep[x] < 599999 )
							{
								reference = reference / 6;
							} 
							else if (indep[x] > 10000 && indep[x] < 100000 )
							{
								reference = 18762 + (reference / 5);
							}
							else if (indep[x] > 0 && indep[x] < 10000 )
							{
								reference = 13963 + reference;
							} 
							else 
							{
								reference = reference / 7;	
							}
						
							cout << "\n---------------------------------------\n";
							cout << "Withdrawal Successful!\n";
							cout << "Name              : " << fname[x] << " " << lname[x] << "\n";
							cout << "Account Number    : " << num[x] << "\n";
							cout << "Withdrawn Amount  : Php " << withdraw << "\n";
							cout << "Reference No.     : " << reference << "\n";
									
							if ( acc[x] == "A1" && indep[x] < 10000)
							{
								indep[x] -= 300;
								cout << "---------------------------------------\n\n";
								cout << "Penalty Applied     : Php 300.00\n";
								cout << "Outstanding Balance : Php " << indep[x] << "\n";
								cout << "---------------------------------------\n\n";
							} 
							else if ( acc[x] == "A2" && indep[x] < 5000)
							{
								indep[x] -= 300;
								cout << "---------------------------------------\n\n";
								cout << "Penalty Applied     : Php 300.00\n";
								cout << "Outstanding Balance : Php " << indep[x] << "\n";
								cout << "---------------------------------------\n\n";
							}
							else
							{
								cout << "---------------------------------------\n";
								cout << "Outstanding Balance : Php " << indep[x] << "\n";
								cout << "---------------------------------------\n\n";
							}
						
							//withdrawals transaction history
							transacdate[all] = __DATE__;
							ref[all] = reference;
							amnt[all] = withdraw;
							balance[all] = indep[x];
							mark[all] = x;
							type[all] = "with";
							all++;
								
							check++;
							loop = false;
						}
					}
					else
					{
						cout << "\n\n Processing transfer....\n\n";
						cout << "Error: Insufficient balance!\n";
						cout << "Your available balance is Php " << indep[x] <<"\n";
						cout << "Please enter a smaller amount or deposit funds first.\n";
						loop = false;
					}	
				}
			}
			if(check == 0)
			{
				cout << "\n                No Matching Account Found\n";
				cout << "Please make sure you entered correctly the following information \n\n";
			}	
			
			break;
		case 4: //transfer money
			loop = true;
			check = 0;
			
			while (loop)
			{
				cout << "       MONEY TRANSFER     \n\n"; 
				cout << "Account number: ";
				cin >> accnum;
				cout << "Code          : ";
				cin >> Wcode;
				cout << "\n\nEnter Recipient Account No. : ";
				cin >> recipient;
				cout << "Enter Amount to Transfer    : ";
				cin >> withdraw;
				
				for (x=0; x < count; x++)
				{
					if (accnum == num[x] && code[x] == Wcode)
					{
						check++;
						if (withdraw <= indep[x])
						{	
							if (indep[x] - withdraw < maintaining[x])
							{
									
								bool recipientFound = false;
								cout << "Notice: Withdrawing this amount may include a penalty fee.\n";
								cout << "Your account balance may fall below the maintaining balance.\n";
								cout << "A penalty fee of Php 300 will be applied if the balance goes below this limit.\n";
								cout << "Do you still want to continue with the withdrawal? (Y/N): ";
								cin >> notice;
								
								if (notice == 'Y' || notice == 'y')
								{
								
									for (y = 0; y < count; y++)
									{
										if ( recipient == num[y] )
										{
											recipientFound = true;
											indep[x] = indep[x] - withdraw;
											indep[y] = indep[y] + withdraw;
											reference = indep[x];
								
											if (indep[x] > 100000 && indep[x] < 599999 )
											{
												reference = reference / 6;
											} 
											else if (indep[x] > 10000 && indep[x] < 100000 )
											{
												reference = 18762 + (reference / 5);
											}
											else if (indep[x] > 0 && indep[x] < 10000 )
											{
												reference = 13963 + reference;
											} 
											else 
											{
												reference = reference / 7;	
											}
											
											cout << "\n---------------------------------------\n";
											cout << "              Transfer successful!            \n";
											cout << "Sender            : " << fname[x] + " " << lname[x] + "\n";
											cout << "Account Number    : " << num[x] << "\n";
											cout << "Transferred Amount: Php " << withdraw << "\n";
											if ( acc[x] == "A1" && indep[x] < 10000)
												{
													indep[x] -= 300;
													cout << "Penalty Applied     : Php 300.00\n";
													cout << "Outstanding Balance : Php " << indep[x] << "\n";
												} 
												else if ( acc[x] == "A2" && indep[x] < 5000)
												{
													indep[x] -= 300;
													cout << "Penalty Applied     : Php 300.00\n";
													cout << "Outstanding Balance : Php " << indep[x] << "\n";
												}
												else
												{
													cout << "Outstanding Balance : Php " << indep[x] << "\n";
												}
									
											cout << "Recipient Account Number : " << recipient << "\n";
											cout << "Amount Received          : Php " << withdraw << "\n";
											cout << "\n---------------------------------------\n";
											
											//transaction history ni sender
											transacname[all] = fname[y] + (" " + lname[y]);
											transacdate[all] = __DATE__;
											ref[all] = reference;
											amnt[all] = withdraw;
											balance[all] = indep[x];
											mark[all] = x;
											type[all] = "send";
												
											all++;
											//transaction history ni receiver
											transacname[all] = first + (" " + last);
											transacdate[all] = __DATE__;
											ref[all] = reference;
											amnt[all] = withdraw;
											balance[all] = indep[y];
											mark[all] = y;
											type[all] = "receive";
												
											all++;	
					
											loop = false;
											break;
										}
									}
								}
								else
								{
									cout << "\n        Your available balance is Php " << indep[x] <<"\n";
									cout << "Please enter a smaller amount or deposit funds first.\n";
									loop = false;	
								}
								
							if ( !recipientFound )
							{
								cout << "\nError: Recipient account number not found! \n";
								cout << "Please check the account number and try again\n"; 
							}
							}
							else
							{	
								bool recipientFound = false;	
								for (y = 0; y < count; y++)
								{
									if ( recipient == num[y] )
									{
										recipientFound = true;
										indep[x] = indep[x] - withdraw;
										indep[y] = indep[y] + withdraw;
										reference = indep[x];
					
										if (indep[x] > 100000 && indep[x] < 599999 )
										{
											reference = reference / 6;
										} 
										else if (indep[x] > 10000 && indep[x] < 100000 )
										{
											reference = 18762 + (reference / 5);
										}
										else if (indep[x] > 0 && indep[x] < 10000 )
										{
											reference = 13963 + reference;
										} 
										else 
										{
											reference = reference / 7;	
										}
									
										cout << "\n---------------------------------------\n";
										cout << "              Transfer successful!            \n";
										cout << "Sender            : " << fname[x] + " " << lname[x] + "\n";
										cout << "Account Number    : " << num[x] << "\n";
										cout << "Transferred Amount: Php " << withdraw << "\n";
										if ( acc[x] == "A1" && indep[x] < 10000)
										{
											indep[x] -= 300;
											cout << "Penalty Applied     : Php 300.00\n";
											cout << "Outstanding Balance : Php " << indep[x] << "\n";
										} 
										else if ( acc[x] == "A2" && indep[x] < 5000)
										{
											indep[x] -= 300;
											cout << "Penalty Applied     : Php 300.00\n";
											cout << "Outstanding Balance : Php " << indep[x] << "\n";
										}
										else
										{
											cout << "Outstanding Balance : Php " << indep[x] << "\n";
										}
										
										cout << "Recipient Account Number : " << recipient << "\n";
										cout << "Amount Received          : Php " << withdraw << "\n";
										cout << "\n---------------------------------------\n";
												
										//transaction history ni sender
										transacname[all] = fname[y] + (" " + lname[y]);
										transacdate[all] = __DATE__;
										ref[all] = reference;
										amnt[all] = withdraw;
										balance[all] = indep[x];
										mark[all] = x;
										type[all] = "send";
																					
										all++;
										//transaction history ni receiver
										transacname[all] = first + (" " + last);
										transacdate[all] = __DATE__;
										ref[all] = reference;
										amnt[all] = withdraw;
										balance[all] = indep[y];
										mark[all] = y;
										type[all] = "receive";
												
										all++;	
						
										loop = false;
										break;
									}
								}
							}
	
						}
						else
						{
							cout << "\n\n Processing transfer....\n\n";
							cout << "Error: Insufficient balance!\n";
							cout << "Your available balance is Php " << indep[x] <<"\n";
							cout << "Please enter a smaller amount or deposit funds first.\n";	
							loop = false;
						}
					}
				}
				if(check == 0)
				{
				cout << "\n                No Matching Account Found\n";
				cout << "Please make sure you entered correctly the following information \n\n";
				}	
				
			}
			break;
		case 5: //balance
			loop = true;
			check = 0;
			
			while(loop)
			{
			cout << "           Balance Inquiry     \n\n"; 
			cout << "Account number: ";
			cin >> accnum;
			cout << "Code          : ";
			cin >> Wcode;
			
			for (x=0; x < count; x++)
			{
				if (accnum == num[x] && code[x] == Wcode)
				{					
    				cout << "\n---------------------------------------\n";
    				cout << "Balance Inquiry Successful!\n";
   					cout << "Name               : " << first << " " << last << "\n";
    				cout << "Account Number     : " << num[x] << "\n";
    				cout << "Available Balance  : " << indep[x] << "\n";
    				cout << "---------------------------------------\n";
					check++;
					loop = false;
				}	
			}
				if(check == 0)
				{
					cout << "\n      No Matching Account Found\n";
					cout << "Please make sure you entered correct information\n\n";
				}
			
			}
			break;
		
		case 6: //summary
			loop = true;
			check = 0;
			
			while(loop)
			{
			cout << "           Summary     \n\n"; 
			cout << "Account number: ";
			cin >> accnum;
			
			for (x=0; x < count; x++)
			{
				if((accnum == num[x]))
				{
					cout << "\n-----------------------------------------------------------------------------------------------------------------------------\n";  
					cout << "Account Holder      : " << fname[x] << " " << lname[x] << "\n";
					cout << "Account Number      : " << num[x] << "\n";
					if (acc[x] == "A1")
					{
						cout << "Account Type        : Savings with Booklet and ATM \n";
						cout << "Maintaining Balance : 10,000 \n";
				
					} 
					else if (acc[x] == "A2") 
					{
						cout << "Account Type        : Savings with ATM only \n";
						cout << "Maintaining Balance : 5,000 \n";
					}
					else
					{
						cout << "Account Type        : Cash Card \n";
						cout << "No Maintaining Balance \n";
					}
					cout << "Available Balance   : " << indep[x] << "\n";
					cout << "Opened On           : " << date[x] << "\n\n";
					cout << "                                                           DEPOSITS                                                     \n";
					cout << "-----------------------------------------------------------------------------------------------------------------------------\n"; 
					cout << "     Date      |                    Description                   |         Ref no.        |              Amount       \n";
					cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
					
					for (y = 0; y <= all; y++)
					{
						
						if (type[y] == "dep" && mark[y] == x)
						{
							cout << " " <<  transacdate[y] << "      Cash deposit by teller                                    " << ref[y];
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y]< 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] < 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                      " << amnt[y] << "\n";
							}
							check++;
						} 
						else if ( type[y] == "receive" && mark[y] == x )
						{
							
							if (transacname[y].length() < 32)
							{
								space = 35 - transacname[y].length();
								spacing = transacname[y];
									
								for (s = 0; s < space; s++)
								{
									spacing += " ";	
								}
							}
							else
							{
								spacing = transacname[y];
							}
							cout << " " <<  transacdate[y] << "     Transfer from "<< spacing << "          " << ref[y];  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] < 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                      " << amnt[y] << "\n";
							}
							check++;
						}
					}
					cout << " \n                                                        WITHDRAWALS                                    \n";
				   	cout << "-----------------------------------------------------------------------------------------------------------------------------\n"; 
					cout << "     Date      |                    Description                   |         Ref no.        |              Amount       \n";
					cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
              
					for (y = 0; y <= all; y++)
					{
						
						if (type[y] == "with" && mark[y] == x)
						{
							cout << " " << transacdate[y] << "      Cash withdrawal via teller                                " << ref[y] ;
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] < 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                  Php " << amnt[y] << "\n";
							}
							check++;
						} 
						else if ( type[y] == "send" && mark[y] == x)
						{

							if (transacname[y].length() < 32)
							{
								space = 37 - transacname[y].length();
								spacing = transacname[y];
								for (s = 0; s < space; s++)
								{
									spacing += " ";	
								}
							}
							else
							{
								spacing = transacname[y];
							}
								
							cout << " " << transacdate[y] << "     Transfer to "<< spacing << "          " << ref[y] ;  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                  Php " << amnt[y] << "\n";
							}
							check++;
						}
						
					}
					cout << "\nDo you want to save transaction history to a file? (Y/N): ";
					cin >> answer;
					
					if ( answer == 'y' || answer == 'Y' )
					{
						cout << "AccountSummary.txt";
						
						files << "Account Holder      : " << fname[x] << " " << lname[x] << "\n";
						files << "Account Number      : " << num[x] << "\n";
						files << "                                                           DEPOSITS                                                     \n";
						files << "-----------------------------------------------------------------------------------------------------------------------------\n"; 
						files << "     Date      |                    Description                   |         Ref no.        |              Amount       \n";
						files << "-----------------------------------------------------------------------------------------------------------------------------\n";
					
					for (y = 0; y <= all; y++)
					{
						
						if (type[y] == "dep" && mark[y] == x)
						{
							files << " " <<  transacdate[y] << "      Cash deposit by teller                                    " << ref[y];
							
							if ( amnt[y] < 1000 )
							{
								files << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								files << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y]< 100000 )
							{
								files << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] < 1000000)
							{
								files << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								files << "                      " << amnt[y] << "\n";
							}
							check++;
						} 
						else if ( type[y] == "receive" && mark[y] == x )
						{
							
							if (transacname[y].length() < 32)
							{
								space = 35 - transacname[y].length();
								spacing = transacname[y];
									
								for (s = 0; s < space; s++)
								{
									spacing += " ";	
								}
							}
							else
							{
								spacing = transacname[y];
							}
							files << " " <<  transacdate[y] << "     Transfer from "<< spacing << "          " << ref[y];  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								files << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								files << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								files << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] < 1000000)
							{
								files << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								files << "                      " << amnt[y] << "\n";
							}
							check++;
						}
					}
					files << " \n                                                        WITHDRAWALS                                    \n";
				   	files << "-----------------------------------------------------------------------------------------------------------------------------\n"; 
					files << "     Date      |                    Description                   |         Ref no.        |              Amount       \n";
					files << "-----------------------------------------------------------------------------------------------------------------------------\n";
	       
					for (y = 0; y < all; y++)
					{
						
						if (type[y] == "with" && mark[y] == x)
						{
							files << " " << transacdate[y] << "      Cash withdrawal via teller                                " << ref[y] ;
							
							if ( amnt[y] < 1000 )
							{
								files << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								files << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								files << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								files << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								files << "                  Php " << amnt[y] << "\n";
							}
						} 
						else if ( type[y] == "send" && mark[y] == x)
						{
							for (c = 0; c < count; c++)
							{
								if (transacname[y].length() < 32)
								{
									space = 37 - transacname[y].length();
									spacing = transacname[y];
									for (s = 0; s < space; s++)
									{
										spacing += " ";	
									}
								}
							}
							files << " " << transacdate[y] << "     Transfer to "<< spacing << "          " << ref[y] ;  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								files << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								files << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								files << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								files << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								files << "                  Php " << amnt[y] << "\n";
							}
						}
						
					}

					}
					
					files.close();
					
					cout << "\nHistory saved to AccountSummary.txt\n";
					loop = false;
					}
					else
					{
						loop = false;
					}
					}
				
					
				if(check == 0)
				{
					cout << "\n      No Matching Account Found\n";
					cout << "Please make sure you entered correct information\n\n";
				}			
			}
			break;
			
		case 7: //per acc
			loop = true;
			check = 0;
			
			while(loop)
			{
			cout << "           Summary     \n\n"; 
			cout << "Account number: ";
			cin >> accnum;
			
			for (x=0; x < count; x++)
			{
				if (accnum == num[x])
				{
					cout << " Account Report \n";
					cout << "Account Number      : " << num[x] << "\n";
					cout << "Account Holder      : " << fname[x] << " " << lname[x] << "\n";
					if (acc[x] == "A1")
					{
						cout << "Account Type        : Savings with Booklet and ATM \n";
						cout << "Maintaining Balance : 10,000 \n";
				
					} 
					else if (acc[x] == "A2") 
					{
						cout << "Account Type        : Savings with ATM only \n";
						cout << "Maintaining Balance : 5,000 \n";
					}
					else
					{
						cout << "Account Type        : Cash Card \n";
						cout << "No Maintaining Balance \n";
					}
					cout << "Date opened         : " << date[x] << "\n";
					cout << "Available Balance   : " << indep[x] << "\n\n";
					
					cout << "                                                          Account Statement                               " << "\n";
					cout << "-----------------------------------------------------------------------------------------------------------------------------\n";  
					cout << "     Date      |                    Description                   |        Ref no.         |              Amount       \n";
					cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
					
					for (y = 0; y < all; y++)
					{
						
						if (type[y] == "dep" && mark[y] == x)
						{
							cout << " " <<  transacdate[y] << "      Cash deposit by teller                                    " << ref[y];
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                  Php " << amnt[y] << "\n";
							}
						} 
						else if ( type[y] == "receive" && mark[y] == x)
						{
							for (c = 0; c < count; c++)
							{
								if (transacname[y].length() < 35)
								{
									space = 35 - transacname[y].length();
									spacing = transacname[y];
									for (s = 0; s < space; s++)
									{
										spacing += " ";	
									}
								}
							}
							cout << " " << transacdate[y] << "     Transfer from "<< spacing << "          " << ref[y] ;  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                  Php " << amnt[y] << "\n";
							}
						} 
						else if (type[y] == "with" && mark[y] == x)
						{
							cout << " " << transacdate[y] << "      Cash withdrawal via teller                                " << ref[y];
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                  Php " << amnt[y] << "\n";
							}
						} 
						else if (type[y] == "send" && mark[y] == x)
						{
							for (c = 0; c < count; c++)
							{
								if (transacname[y].length() < 37)
								{
									space = 37 - transacname[y].length();
									spacing = transacname[y];
									for (s = 0; s < space; s++)
									{
										spacing += " ";	
									}
								}
							}
							cout << " " << transacdate[y] << "     Transfer to " << spacing << "          " << ref[y];  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								cout << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								cout << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								cout << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								cout << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								cout << "                  Php " << amnt[y] << "\n";
							}
						}
						
					}
					cout << "\nDo you want to save transaction history to a file? (Y/N): ";
				cin >> answer;
					
				if ( answer == 'y' || answer == 'Y' )
				{
					per << "Account Holder      : " << fname[x] << " " << lname[x] << "\n";
					per << "Account Number      : " << num[x] << "\n";
					per << "-----------------------------------------------------------------------------------------------------------------------------\n";
					per << "                                                          Account Statement                               " << "\n\n";
					per << "-----------------------------------------------------------------------------------------------------------------------------\n";  
					per << "     Date      |                    Description                   |        Ref no.         |              Amount       \n";
					per << "-----------------------------------------------------------------------------------------------------------------------------\n";
					
					for (y = 0; y < all; y++)
					{
						
						if (type[y] == "dep" && mark[y] == x)
						{
							per << " " <<  transacdate[y] << "      Cash deposit by teller                                    " << ref[y];
							
							if ( amnt[y] < 1000 )
							{
								per << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								per << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								per << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								per << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								per << "                  Php " << amnt[y] << "\n";
							}
						} 
						else if ( type[y] == "receive" && mark[y] == x)
						{
							for (c = 0; c < count; c++)
							{
								if (transacname[y].length() < 32)
								{
									space = 35 - transacname[y].length();
									spacing = transacname[y];
									for (s = 0; s < space; s++)
									{
										spacing += " ";	
									}
								}
							}
							per << " " << transacdate[y] << "     Transfer from "<< spacing << "          " << ref[y] ;  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								per << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								per << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								per << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								per << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								per << "                  Php " << amnt[y] << "\n";
							}
						} 
						else if (type[y] == "with" && mark[y] == x)
						{
							per << " " << transacdate[y] << "      Cash withdrawal via teller                                " << ref[y];
							
							if ( amnt[y] < 1000 )
							{
								per << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								per << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								per << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								per << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								per << "                  Php " << amnt[y] << "\n";
							}
						} 
						else if (type[y] == "send" && mark[y] == x)
						{
							for (c = 0; c < count; c++)
							{
								if (transacname[y].length() < 37)
								{
									space = 37 - transacname[y].length();
									spacing = transacname[y];
									for (s = 0; s < space; s++)
									{
										spacing += " ";	
									}
								}
							}
							per << " " << transacdate[y] << "     Transfer to " << spacing << "          " << ref[y];  //transac name send money
							
							if ( amnt[y] < 1000 )
							{
								per << "                       Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 999 && amnt[y] < 10000 )
							{
								per << "                      Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 9999 && amnt[y] < 100000 )
							{
								per << "                     Php " << amnt[y] << "\n";
							}
							else if ( amnt[y] > 99999 && amnt[y] > 1000000)
							{
								per << "                    Php " << amnt[y] << "\n";
							}
							else
							{
								per << "                  Php " << amnt[y] << "\n";
							}
						}
						
					}
					per.close();
					cout << "\nHistory saved to AccountStatement.txt\n";
					loop = false;
				}
				else
				{ 
					loop = false;	
				}
				}
				}
				
			}
			break;
			
			
		case 8: //report
			
			cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
			cout << "                                                    All accounts Report                                                    \n";
			cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
			cout << "  Account Number |                   Account Holder                  | Account Type |    Available Balance    |  Date Opened     \n";
			cout << "-----------------------------------------------------------------------------------------------------------------------------\n";   //21 space including PHP   date = 11 spaces
			
			for (x = 0; x < count; x++)
			{
				for (c = 0; c < count; c++)
				{
					space = fname[x].length() + lname[x].length() + 1;
					
					if (space < 48)
					{
						space =  48 - space;
						spacing = fname[x] + " " + lname[x];
						for (s = 0; s < space; s++)
						{
							spacing += " ";	
						}
					}
				}
				
				cout << "     " << num[x] << "       " << spacing << "       " << acc[x] << "    ";
				
				if ( amnt[x] < 1000 )
				{
					cout << "                 Php " << indep[x] << "           " << date[x] << "\n";
				}
				else if ( amnt[x] > 999 && amnt[x] < 10000 )
				{
					cout << "                Php " << indep[x] << "           " << date[x] << "\n";
				}
				else if ( amnt[x] > 9999 && amnt[x] < 100000 )
				{
					cout << "               Php " << indep[x] << "           " << date[x] << "\n";
				}
				else if ( amnt[x] > 99999 && amnt[x] < 1000000)
				{
					cout << "              Php " << indep[x] << "           " << date[x] << "\n";
				}
				else
				{
					cout << "             Php " << indep[x] << "           " << date[x] << "\n";
				}	
			}
			cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
			
			cout << "\nDo you want to save transaction history to a file? (Y/N): ";
			cin >> answer;
					
			if ( answer == 'y' || answer == 'Y' )
			{
				allacc << "-----------------------------------------------------------------------------------------------------------------------------\n";
				allacc << "                                                    All accounts Report                                                    \n";
				allacc << "-----------------------------------------------------------------------------------------------------------------------------\n";
				allacc << "  Account Number |                   Account Holder                 | Account Type |    Available Balance    |  Date Opened     \n";
				allacc << "-----------------------------------------------------------------------------------------------------------------------------\n";   //21 space including PHP   date = 11 spaces
			
			for (x = 0; x < count; x++)
			{
				for (c = 0; c < count; c++)
				{
					space = fname[x].length() + lname[x].length() + 1;
					
					if (space < 48)
					{
						space =  48 - space;
						spacing = fname[x] + " " + lname[x];
						for (s = 0; s < space; s++)
						{
							spacing += " ";	
						}
					}
				}
				
				allacc << "     " << num[x] << "       " << spacing << "       " << acc[x] << "    ";
				
				if ( amnt[x] < 1000 )
				{
					allacc << "                 Php " << indep[x] << "           " << date[x] << "\n";
				}
				else if ( amnt[x] > 999 && amnt[x] < 10000 )
				{
					allacc << "                Php " << indep[x] << "           " << date[x] << "\n";
				}
				else if ( amnt[x] > 9999 && amnt[x] < 100000 )
				{
					allacc << "               Php " << indep[x] << "           " << date[x] << "\n";
				}
				else if ( amnt[x] > 99999 && amnt[x] < 1000000)
				{
					allacc << "              Php " << indep[x] << "           " << date[x] << "\n";
				}
				else
				{
					allacc << "             Php " << indep[x] << "           " << date[x] << "\n";
				}	
			}
			allacc << "-----------------------------------------------------------------------------------------------------------------------------\n";	
			allacc.close();
			cout << "\nHistory saved to ReportAllAccount.txt\n";
			loop = false;
			
			}
			else
			{
				loop = false;
			}
		
			
			
			break;
		case 9:
			cout << "Exiting program.... Thankyou!!";
			inloop = false;
			break;
		}
	}
}
}
