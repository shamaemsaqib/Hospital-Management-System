#include<iostream>
using namespace std;

int main()
{
	bool end = 1;
	double current_date;
	//Variables For Feature 1
	char service_choice;
	int remaining;
	int i = 0;
	int id[1000], age[1000], disease[1000], specialist[1000], bill[1000], paid[1000], due[1000];
	char sex[1000], service[1000];
	int count_o = 0, count_e = 0;

	//Variables for Feature 2
	char edit_choice;
	int search_id;
	int recordnumber;

	//Variables for Feature 3
	char list_choice;
	double date;

	//Variables for Feature 4
	int delete_id, z = 0;
	char delete_choice;
	int counter = 0;

	cout << "_____________________________________________________\n\n";
	cout << "                    WELCOME TO\n";
	cout << "\n";
    cout << "           \"HOSPITAL MANAGEMENT SYSTEM\"\n";
	cout << "______________________________________________________";
	cout << endl << endl;
	system("pause");
	system("CLS");
	cout << "Enter Current Date(DDMMYYY): ";
	cin >> current_date;
	cout << endl;
	do
	{
		cout << "*********************************************\n\n";
		cout << "Enter 1 to Add new patient record\n";
		cout << "Enter 2 to Search or edit patient record\n";
		cout << "Enter 3 to List record of patients\n";
		cout << "Enter 4 to Delete patient records\n";
		cout << "Enter 5 to Exit the Program\n\n";
		cout << "**********************************************\n\n";
		char feature;
		cin >> feature;
		system("CLS");
		if (feature == '1' || feature == '2' || feature == '3' || feature == '4')
		{
			if (feature == '1')
			{
				cout << "*****************************\n\n";
				cout << "Add New Patient Record\n\n";
				cout << "*****************************\n";
			    a:
				cout << "Enter 1 to add new patient record in O.P.D. Service\n";
				cout << "Enter 2 to add new patient record in Emergency Service\n";
				cin >> service_choice;
				if (service_choice == '1' || service_choice == '2')
				{
					system("CLS");
					cout << "*****************************\n\n";
					cout << "New Patient Reccord\n\n";
					cout << "*****************************\n";
					cout << "Patient ID: " << i + 1 << endl << endl;
					id[i] = i + 1;
					if (service_choice == '1')
					{
						service[i] = 'o';
						count_o++;
					}
					else if (service_choice == '2')
					{
						service[i] = 'e';
						count_e++;
					}
					cout << "Enter Age of Patient: ";
					cin >> age[i];
					cout << endl;
					z:
					cout << "Enter Sex of Patient(m/f): ";
					cin >> sex[i];
					cout << endl;
					if (sex[i] != 'm' && sex[i] != 'M' && sex[i] != 'f' && sex[i] != 'F')
					{
						cout << "Wrong Input\n\n";
						goto z;
					}
					cout << "Enter Disease ID of Patient: ";
					cin >> disease[i];
					cout << endl;
					cout << "Enter Reffered Specialist Room Number of Patient: ";
					cin >> specialist[i];
					cout << endl;
					cout << "Enter Total Bill of Patient: ";
					cin >> bill[i];
					cout << endl;
					cout << "Enter Bill Paid by Patient: ";
					cin >> paid[i];
					cout << endl;
					remaining = bill[i] - paid[i];
					cout << "Remaining Bill of Patient: " << remaining << endl;
					due[i] = remaining;
					cout << endl;
					cout << "______________________________________________________\n\n";
					cout << "Record Saved Successfully!\n";
					i++;
					system("pause");
				}
				else
				{
					cout << "Wrong Input!\n\n";
					goto a;
				}
			}
			else if (feature == '2')
			{
				cout << "*****************************\n\n";
				cout << "Search or edit patient record:\n\n";
				cout << "*****************************\n";
				cout << "Enter Patient ID: ";
				cin >> search_id;
				bool flag = 0;
				for (int a = 0; a < i ; a++)
				{
					if (id[a] == search_id)
					{
						system("CLS");
						recordnumber = id[a] - 1;
						cout << "*****************************\n\n";
						cout << "Record of patient # " << search_id << endl << endl;
						cout << "*****************************\n";
						cout << "Age of Patient: " << age[recordnumber] << endl << endl;
						cout << "Sex of Patient: " << sex[recordnumber] << endl << endl;
						cout << "Disease of Patient: " << disease[recordnumber] << endl << endl;
						cout << "Reffered Room of Specialist of Patient: " << specialist[recordnumber] << endl << endl;
						cout << "Total Bill of Patient: " << bill[recordnumber] << endl << endl;
						cout << "Bill Paid by Patient: " << paid[recordnumber] << endl << endl;
						cout << "Remaining Bill of Patient: " << due[recordnumber] << endl << endl;
						cout << "______________________________________________________\n\n";
						flag = 1;
						cout << "Do you want to Edit this Record(y/n): ";
						cin >> edit_choice;
						if (edit_choice == 'y' || edit_choice == 'Y')
						{
							cout << "Age of Patient: ";
							cin >> age[recordnumber];
							cout << endl;
							y:
							cout << "Sex of Patient(m/f): ";
							cin >> sex[recordnumber];
							cout << endl;
							if (sex[recordnumber] != 'm' && sex[recordnumber] != 'M' && sex[recordnumber] != 'f' && sex[recordnumber] != 'F')
							{
								cout << "Wrong Input!\n\n";
								goto y;
							}
							cout << "Disease of Patient: ";
							cin >> disease[recordnumber];
							cout << endl;
							cout << "Reffered Room of Specialist of Patient: ";
							cin >> specialist[recordnumber];
							cout << endl;
							cout << "Total Bill of Patient: ";
							cin >> bill[recordnumber];
							cout << endl;
							cout << "Bill Paid by Patient: ";
							cin >> paid[recordnumber];
							cout << endl;
							remaining = bill[recordnumber] - paid[recordnumber];
							cout << "Remaining Bill of Patient: " << remaining << endl;
							cout << endl;
							due[recordnumber] = remaining;
							cout << "______________________________________________________\n\n";
							cout << "Record Updated Successfully!\n";
							break;
						}
					}
				}
				if (flag == 0)
				{
					cout << "No Record Found!\n";
				}
				system("pause");
			}
			else if (feature == '3')
			{
				cout << "*****************************\n\n";
				cout << "List Record of Patients\n\n";
				cout << "*****************************\n";
			b:
				cout << "Enter 1 to List Records of patients sort by ids\n";
				cout << "Enter 2 to List Records of Emergency patients\n";
				cout << "Enter 3 to List Records of O.P.D. patients\n";
				cout << "Enter 4 to list Records of patients in a particular date\n";
				cin >> list_choice;
				if (list_choice == '1')
				{
					system("CLS");
					int count1 = 0;
					cout << "*****************************\n\n";
					cout << "Record of Patient Sort by ID\n\n";
					cout << "*****************************\n";
					for (int a = 0; a < i; a++)
					{
						cout << "______________________________________________________\n";
						cout << "Patient ID: " << id[a] << endl << endl;
						cout << "Age of Patient: " << age[a] << endl << endl;
						cout << "Sex of Patient: " << sex[a] << endl << endl;
						cout << "Disease of Patient: " << disease[a] << endl << endl;
						cout << "Reffered Room of Specialist of Patient: " << specialist[a] << endl << endl;
						cout << "Total Bill of Patient: " << bill[a] << endl << endl;
						cout << "Bill Paid by Patient: " << paid[a] << endl << endl;
						cout << "Remaining Bill of Patient: " << due[a] << endl << endl;
						cout << "______________________________________________________\n\n";
						count1++;
					}
					if (count1 == 0)
					{
						cout << "No Records Available!" << endl;
					}
					system("pause");
				}
				else if (list_choice == '2')
				{
					system("CLS");
					int count2 = 0;
					cout << "**********************************\n\n";
					cout << "Records of Emergency Patients\n\n";
					cout << "**********************************\n\n";
					for (int a = 0; a < i; a++)
					{
						if (service[a] == 'e')
						{
							cout << "______________________________________________________\n";
							cout << "Patient ID: " << id[a] << endl << endl;
							cout << "Age of Patient: " << age[a] << endl << endl;
							cout << "Sex of Patient: " << sex[a] << endl << endl;
							cout << "Disease of Patient: " << disease[a] << endl << endl;
							cout << "Reffered Room of Specialist of Patient: " << specialist[a] << endl << endl;
							cout << "Total Bill of Patient: " << bill[a] << endl << endl;
							cout << "Bill Paid by Patient: " << paid[a] << endl << endl;
							cout << "Remaining Bill of Patient: " << due[a] << endl << endl;
							cout << "______________________________________________________\n\n";
							count2++;
						}
					}
					if (count2 == 0)
					{
						cout << "No Records Available!" << endl;
					}
					system("pause");
				}
				else if (list_choice == '3')
				{
					system("CLS");
					int count3 = 0;
					cout << "**********************************\n\n";
					cout << "Records of O.P.D. Service\n\n";
					cout << "**********************************\n";
					for (int a = 0; a < i; a++)
					{
						if (service[a] == 'o')
						{
							cout << "______________________________________________________\n";
							cout << "Patient ID: " << id[a] << endl << endl;
							cout << "Age of Patient: " << age[a] << endl << endl;
							cout << "Sex of Patient: " << sex[a] << endl << endl;
							cout << "Disease of Patient: " << disease[a] << endl << endl;
							cout << "Reffered Room of Specialist of Patient: " << specialist[a] << endl << endl;
							cout << "Total Bill of Patient: " << bill[a] << endl << endl;
							cout << "Bill Paid by Patient: " << paid[a] << endl << endl;
							cout << "Remaining Bill of Patient: " << due[a] << endl << endl;
							cout << "______________________________________________________\n\n";
							count3++;
						}
					}
					if (count3 == 0)
					{
						cout << "No Records Available!" << endl;
					}
					system("pause");
				}
				else if (list_choice == '4')
				{
					system("CLS");
					cout << "*********************************************\n\n";
					cout << "Record of Patients on a Particular Date\n\n";
					cout << "*********************************************\n";
					cout << "Enter Date to Search(DDMMYYYY): ";
					cin >> date;
					int count4 = 0;
					if (current_date == date)
					{
						for (int c = 0; c < i; c++)
						{
							cout << "\n______________________________________________________\n\n";
							cout << "Patient ID # " << id[c] << endl << endl;
							cout << "Age of Patient: " << age[c] << endl << endl;
							cout << "Sex of Patient: " << sex[c] << endl << endl;
							cout << "Disease of Patient: " << disease[c] << endl << endl;
							cout << "Reffered Room of Specialist of Patient: " << specialist[c] << endl << endl;
							cout << "Total Bill of Patient: " << bill[c] << endl << endl;
							cout << "Bill Paid by Patient: " << paid[c] << endl << endl;
							cout << "Remaining Bill of Patient: " << due[c] << endl << endl;
							cout << "______________________________________________________\n\n";
							count4++;
						}
						if (count4 == 0)
						{
							cout << "No Records Found on Given Date!\n";
						}
					}
					else
					{
						cout << "No Records Found on Given Date!\n";
					}
					system("pause");
				}
				else
				{
					cout << "Wrong Input!\n";
					goto b;
				}
			}
			else if (feature == '4')
			{
				cout << "*****************************\n\n";
				cout << "Delete a Patient Record\n\n";
				cout << "*****************************\n";
				cout << "Enter Patient ID to Delete: ";
				cin >> delete_id;
				bool loop = 0;
				for (int a = 0; a < i; a++)
				{
					if (id[a] == delete_id)
					{
						loop = 1;
						z = id[a] - 1;
						system("CLS");
						cout << "Patient ID: " << delete_id << endl << endl;
						cout << "Age of Patient: " << age[z] << endl << endl;
						cout << "Sex of Patient: " << sex[z] << endl << endl;
						cout << "Disease of Patient: " << disease[z] << endl << endl;
						cout << "Reffered Room of Specialist of Patient: " << specialist[z] << endl << endl;
						cout << "Total Bill of Patient: " << bill[z] << endl << endl;
						cout << "Bill Paid by Patient: " << paid[z] << endl << endl;
						cout << "Remaining Bill of Patient: " << due[z] << endl << endl;
					c:
						cout << "______________________________________________________\n\n";
						cout << "Enter D to Delete this Record\n";
						cout << "Enter 1 to Keep this Record\n";
						cin >> delete_choice;
						cout << "\n______________________________________________________\n\n";
						if (delete_choice == 'd' || delete_choice=='D')
						{
							for (int b = a; b < i; b++)
							{
								id[b] = id[b + 1];
								age[b] = age[b + 1];
								sex[b] = sex[b + 1];
								service[b] = service[b + 1];
								disease[b] = disease[b + 1];
								specialist[b] = specialist[b + 1];
								bill[b] = bill[b + 1];
								paid[b] = paid[b + 1];
								due[b] = due[b + 1];
							}
							cout << "Record Deleted Successfully!\n";
							i--;
						}
						else if (delete_choice == '1')
						{
							cout << "Record Not Deleted!\n";
						}
						else
						{
							cout << "Wrong Input\n";
							goto c;
						}
						break;
					}
				}
				if (loop == 0)
				{
					cout << "No Record Found!\n";
				}
				system("pause");

			}
		}
		 else if (feature == '5')
		{
			 cout << "*************************************\n\n";
			cout << "Thankyou for using this Program.\n";
			cout << "Good-Bye!\n\n";
			cout << "*************************************\n\n";
			system("pause");
			end = 0;
		}
		else
		{
			cout << "Wrong Input!" << endl;
			system("pause");
		}
		system("CLS");
	}while (end != 0);
}