// Programming Project 2
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string     mobilePlan, autoPay, paperLess;
    int numberOfLines = 0, baseCost = 0, discountPaperless = 0, discountAutopay = 0, noldisc = 0, gigabytes = 0, dataUsageCharge = 0;
    double cost;
    
    // determining the base cost using the mobile plan
    cout << "What type of cell plan do you have? ";
    getline(cin, mobilePlan);
    
    if (mobilePlan == "Unlimited Elite")
    {
        baseCost = 85;
    }
    else if (mobilePlan == "Unlimited Extra")
    {
        baseCost = 75;
    }
    else if (mobilePlan == "Unlimited Starter")
    {
        baseCost = 65;
    }
    else if (mobilePlan == "Prepaid")
    {
        baseCost = 50;
    }
    else
    {
        cout << "Your cell plan is not valid!" <<endl;
        return (0);
    }
    
    //determining discount using autopay
    cout << "Are you on autopay? ";
    getline (cin, autoPay);
    
    if (autoPay == "Yes")
    {
        discountAutopay = 2;
    }
    else if (autoPay == "No")
    {
        discountAutopay = 0;
    }
    else
    {
        cout << "Your autopay is not valid!" <<endl;
        return (0);
    }
    
    // determining discount using paperless billing
    cout << "Are you on paperless billing? ";
    getline (cin, paperLess);
    
    if (paperLess == "Yes")
    {
        discountPaperless = 3;
    }
    else if (paperLess == "No")
    {
        discountPaperless = 0;
    }
    else
    {
        cout << "Your paperless billing is not valid!" <<endl;
        return (0);
    }
    
    //determining discount by lines
    cout << "How many lines will be on your plan? ";
    cin >> numberOfLines;
    
    if (numberOfLines == 1)
    {
            noldisc = 0;
    }
    else if (numberOfLines > 1 && numberOfLines <= 3)
    {
            noldisc = (numberOfLines * 10);
    }
    else
    {
        cout << "Your lines are not valid!" << endl;
        return (0);
    }
    
    //determining the number of gigabytes
    cout << "How many gigabytes did you consume? ";
    cin >> gigabytes;
    
    if (gigabytes >= 0 && gigabytes <= 4 && mobilePlan == "Prepaid")
    {
        dataUsageCharge = 0;
    }
    else if (gigabytes > 4 && gigabytes <= 30 && mobilePlan == "Prepaid")
    {
        dataUsageCharge = ((gigabytes - 4)/2)*10;
    }
    else if (gigabytes >= 0 && gigabytes <= 30 && mobilePlan != "Prepaid")
    {
        dataUsageCharge = 0;
    }
    else
    {
        cout << "Your gigabytes are not valid!" << endl;
        return (0);
    }
        
    cost = ((baseCost * numberOfLines) + dataUsageCharge - ((discountAutopay + discountPaperless) * numberOfLines) - noldisc);
    
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout << "Your " <<mobilePlan << " cell plan costs $" << cost << "." << endl;
    
    return (0);
}
