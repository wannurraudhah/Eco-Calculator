#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Base class for recyclable items
class RecyclableItem {
protected:
    double weight_kg;

public:
    RecyclableItem() : weight_kg(0) {}
    virtual void addWeight(double kg) = 0;
    virtual double getWeight() const = 0;
    virtual double calculateScore() const = 0;
};

// Derived class for glass items
class Glass : public RecyclableItem {
public:
    void addWeight(double kg) override {
        weight_kg += kg;
    }

    double getWeight() const override {
        return weight_kg;
    }

    double calculateScore() const override {
        return weight_kg * 3;
    }
};

// Derived class for paper items
class Paper : public RecyclableItem {
public:
    void addWeight(double kg) override {
        weight_kg += kg;
    }

    double getWeight() const override {
        return weight_kg;
    }

    double calculateScore() const override {
        return weight_kg * 2;
    }
};

// Derived class for plastic items
class Plastic : public RecyclableItem {
public:
    void addWeight(double kg) override {
        weight_kg += kg;
    }

    double getWeight() const override {
        return weight_kg;
    }

    double calculateScore() const override {
        return weight_kg * 5;
    }
};

class UserID {
    string user_id;
    string avatar;

public:
    UserID(string id, string av) : user_id(id), avatar(av) {}

    string getUserID() const {
        return user_id;
    }

    string getAvatar() const {
        return avatar;
    }
};

class EnergyConsumption {
private:
    double electric_bill;
    double water_bill;

public:
    EnergyConsumption() : electric_bill(0), water_bill(0) {}

    void setElectricBill(double eBill) {
        if (eBill > 100)
            electric_bill = eBill * 0.50;
        else if (eBill > 50)
            electric_bill = eBill * 0.25;
        else if (eBill >= 0)
            electric_bill = eBill * 0.0;
        else {
            cout << "Error: Invalid electric bill value. Please repeat.\n";
        }
    }

    void setWaterBill(double wBill) {
        if (wBill > 30)
            water_bill = wBill * 0.55;
        else if (wBill >= 0)
            water_bill = wBill * 0.0;
        else {
            cout << "Error: Invalid water bill value. Please repeat.\n";
        }
    }

    double getEnergyConsumption() const {
        return electric_bill + water_bill;
    }
};

class EcoCalc {
public:
    int calculateContributionScore(double recycleScore, double energyConsumption) const {
        return recycleScore - energyConsumption;
    }

    string getRanking(int contributionScore) const {
        if (contributionScore >= 100) {
            return "\nExcellent Job! You are very responsible in consumption and production. Keep up the great work!\n";
        } else if (contributionScore >= 20) {
            return "\nGood Effort! There's room for improvement!\n";
        } else {
            return "\nNeeds Improvement! Let's step up your game!\n";
        }
    }
};

class WeeklyTrackingStreak {
private:
    vector<RecyclableItem*> weekly_items;
    int streak;
    int weeks_count;

public:
    WeeklyTrackingStreak() : streak(0), weeks_count(0) {}

    void addWeeklyItem(RecyclableItem* item) {
        weekly_items.push_back(item);
    }

    double calculateTotalRecycleScore() const {
        double totalRecycleScore = 0;
        for (const auto& item : weekly_items) {
            totalRecycleScore += item->calculateScore();
        }
        return totalRecycleScore;
    }

    void evaluateStreak() {
        if (!weekly_items.empty()) {
            streak++;
            weeks_count++;
        }
    }

    int getStreak() const {
        return streak;
    }

    int getWeeksCount() const {
        return weeks_count;
    }

    ~WeeklyTrackingStreak() {
        for (auto item : weekly_items) {
            delete item;
        }
    }
};

void displaySeparator() {
    cout << "-----------------------------------------------------------------" << endl;
}

void displayIntro() {
    cout << endl;
    displaySeparator();
    cout << "Welcome to the Sustainability Tracker!" << endl;
    cout << "Track your recycling and energy usage and make progress in SDG-12 " << endl;
    displaySeparator();
}

void displayAchievements(int streak) {
    if (streak > 0 && streak % 4 == 0) {
        cout << "\nCongratulations! You've completed " << streak << " weeks of tracking!" << endl;
        cout << "Achievement Unlocked: Consistency is Key!" << endl;
    }
}

void displayWeeklyTips() {
    srand(static_cast<unsigned int>(time(0)));
    vector<string> tips = {
            "Enjoy shorter showers to help save water and energy.",
            "Make it a habit to turn off the lights when you leave a room — every little bit helps!",
            "Consider upgrading to low-flow showerheads and toilets for a more eco-friendly home.",
            "Give your plants a drink with recycled gray water from your washing machine — it's a great way to reuse water.",
            "Create a cool and comfortable space by using fans for a nice cross-breeze.",
            "Explore the benefits of solar panels to tap into clean, renewable energy from the sun."
    };
    int randomIndex = rand() % tips.size();
    cout << "\nWeekly Tip: " << tips[randomIndex] << endl;
    displaySeparator();
}

int main() {
    string userID, avatar;
    cout << "\nEnter your user ID: ";
    cin >> userID;
    cout << "Choose your avatar (e.g., EcoWarrior, GreenGuardian): ";
    cin >> avatar;

    UserID user(userID, avatar);
    WeeklyTrackingStreak weeklyStreak;
    EcoCalc ecoCalc;
    EnergyConsumption energyConsumption;
    double electricBill, waterBill;
    int week = 0;

    displayIntro();

    while (true) {
        for (int inputCount = 1; inputCount <= 2; ++inputCount) {
            double glass, paper, plastic;

            cout << "\nWeek " << (week + 1) << ", Input " << inputCount << ":\n";
            cout << "Enter the number of kilograms of glass: ";
            cin >> glass;
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inputCount--; // Retry the current input
                continue;
            }
            cout << "Enter the number of kilograms of paper: ";
            cin >> paper;
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inputCount--; // Retry the current input
                continue;
            }
            cout << "Enter the number of kilograms of plastic: ";
            cin >> plastic;
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inputCount--; // Retry the current input
                continue;
            }

            RecyclableItem* glassItem = new Glass();
            RecyclableItem* paperItem = new Paper();
            RecyclableItem* plasticItem = new Plastic();

            glassItem->addWeight(glass);
            paperItem->addWeight(paper);
            plasticItem->addWeight(plastic);

            weeklyStreak.addWeeklyItem(glassItem);
            weeklyStreak.addWeeklyItem(paperItem);
            weeklyStreak.addWeeklyItem(plasticItem);
        }

        weeklyStreak.evaluateStreak();
        week++;

        displayWeeklyTips();

        if (week % 4 == 0) {
            while (true) {
                cout << "\nEnter your electric bill consumption (RM): ";
                cin >> electricBill;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    energyConsumption.setElectricBill(electricBill);
                    break;
                }
            }

            while (true) {
                cout << "Enter your water bill consumption (RM): ";
                cin >> waterBill;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    energyConsumption.setWaterBill(waterBill);
                    break;
                }
            }

            double totalRecycleScore = weeklyStreak.calculateTotalRecycleScore();
            double totalEnergyConsumption = energyConsumption.getEnergyConsumption();
            int contributionScore = ecoCalc.calculateContributionScore(totalRecycleScore, totalEnergyConsumption);

            cout << "\nTotal Recycle Score: " << totalRecycleScore << "\n";
            cout << "Total Energy Consumption: " << totalEnergyConsumption << "\n";
            cout << "Contribution Score: " << contributionScore << "\n";
            cout << ecoCalc.getRanking(contributionScore) << "\n";
            displaySeparator();
        }

        displayAchievements(weeklyStreak.getStreak());

        cout << "\nWeekly Streak: " << weeklyStreak.getStreak() << "\n";

        string response;
        while (true) {
            cout << "Do you want to continue to the next week? (yes/no): ";
            cin >> response;
            if (response == "yes" || response == "no") {
                break;
            } else {
                cout << "Error: Please enter 'yes' or 'no'." << endl;
            }
        }

        if (response == "no") {
            break;
        }
    }

    cout << "Thank you for using the Sustainability Tracker, " << user.getAvatar() << " (" << user.getUserID() << ")!" << endl;
    cout << "Keep up the great work in promoting sustainability!" << endl;

    return 0;
}
