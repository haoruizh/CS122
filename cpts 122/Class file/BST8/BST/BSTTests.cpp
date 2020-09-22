#include "BSTTests.h"

//void BSTTests::testInsertOnEmptyTree()
//{
//	Data d1(20);
//	// tree is empty
//	this->tree.insert(d1);
//
//	if (d1.getItem() == tree.getRootPtr()->getData().getItem())
//	{
//		cout << "Inserted data correctly!" << endl;
//	}
//	else
//	{
//		cout << "Warning: inserted data incorrectly!" << endl;
//
//	}
//}

void BSTTests::testClassTemplateDataConstruction()
{
    Data<int> d1;
    cout << d1.getItem() << endl;

    Data<char> d2;
    cout << d2.getItem() << endl;
}

