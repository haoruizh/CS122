#include "Header.h"


bool newcustomer(double x)
{
	return ((rand() * x / RAND_MAX ) < 1);
}

int main()
{
	cout << "Bank\n"
		<< "Enter Max size of queue:    ";
	int qs;
	cin >> qs;
	Queue line(qs); //line queue holds up to qs people

	cout << "Enter the number of simulation hours:      ";
	int hours;
	cin >> hours;
	//simulation runs one cycle per minute
	long cyclelimit = MIN_PER_HR * hours; //number of cycle

	cout << "Enter the average number of customers per hour:   ";
	double perhour; //average # of arrival per hour;
	cin >> perhour;
	double min_per_cust; // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp; //new customer data
	long turnaways=0, customers=0, served=0, sum_line=0, wait_time=0,line_wait=0;

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
		{
			wait_time--;
		}

		sum_line += line.queuecount();
	}

	if (customers > 0)
	{
		cout << "Customers accepted: " << customers << endl
			<< " Customers served: " << served << endl
			<< "	turnaways: " << turnaways << endl
			<< "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "average wait time" << (double)line_wait / served << " minutes";
	}
	else
	{
		cout << "NO CUSTOMERS\n";
	}
	cout << "Done\n";
	return 0;
}