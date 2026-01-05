#include <iostream>
#include <string>

std::string FactoryName; // Factory Name

double FactoryAsset = 0; // Factory Total Money

int RawMaterials = 0; // Raw Materials Value
int Product = 0; // Project Value

int NumberProduct;
int NeededRaw;          // Calculated AFTER user input

int NumberRawMaterials;
int NeededMoney;        // Calculated AFTER user input

int Vote; // Menu Selection-Vote

// Displays factory statistics
void StatisticMenu(){
    std::cout << "-------------------------" << std::endl;
    std::cout << "Factory Name: " << FactoryName << std::endl;
    std::cout << "Raw Materials: " << RawMaterials << std::endl;
    std::cout << "Product: " << Product << std::endl;
    std::cout << "Factory Asset: $" << FactoryAsset << std::endl;
    std::cout << "-------------------------" << std::endl << std::endl;
}

// Displays main menu options
void MainMenu(){
    std::cout << "[1] - Get information about the product" << std::endl;
    std::cout << "[2] - Make product" << std::endl;
    std::cout << "[3] - Sell product" << std::endl;
    std::cout << "[4] - Buy raw materials" << std::endl;
    std::cout << "[5] - Exit" << std::endl;
}

// Initial welcome screen
void Welcome(){
    std::cout << "Hello, enter your factory name: ";
    getline(std::cin, FactoryName);

    std::cout << "I've given you $5,000 in assets as a gift for testing my project!\n\n";
    FactoryAsset += 5000;
}

// Displays product information
void ProductInformation(){
    std::cout << "You can produce 1 product for every 100 raw materials." << std::endl;
    std::cout << "You earn money by selling the products you produce.\n" << std::endl;
}

// Gets user menu selection-vote
void VoteFunction(){
    std::cout << "Vote: ";
    std::cin >> Vote;
}

int main(){
    Welcome();

    while(true){
        StatisticMenu();
        MainMenu();
        VoteFunction();

        switch(Vote){
        case 1:
            ProductInformation();
            break;


        case 2:
            std::cout << "How many products do you want to make: ";
            std::cin >> NumberProduct;

            NeededRaw = NumberProduct * 100;

            if(RawMaterials >= NeededRaw){
                RawMaterials -= NeededRaw;
                Product += NumberProduct;

                std::cout << "You made " << NumberProduct << " product(s).\n\n";
            }
            else{
                std::cout << "Raw materials are insufficient!\n\n";
            }
            break;


        case 3:
            std::cout << "How many products would you like to sell for $1000 each: ";
            std::cin >> NumberProduct;

            if(Product >= NumberProduct){
                Product -= NumberProduct;
                FactoryAsset += (NumberProduct * 1000);

                std::cout << "You sold " << NumberProduct << " product(s).\n\n";
            }
            else{
                std::cout << "You do not have enough products!\n\n";
            }
            break;


        case 4:
            std::cout << "[1 raw material = $2] Enter the amount: ";
            std::cin >> NumberRawMaterials;

            NeededMoney = NumberRawMaterials * 2;

            if(NumberRawMaterials > 0 && FactoryAsset >= NeededMoney){
                FactoryAsset -= NeededMoney;
                RawMaterials += NumberRawMaterials;

                std::cout << "You bought " << NumberRawMaterials << " raw material(s).\n\n";
            }
            else{
                std::cout << "Insufficient money or invalid amount!\n\n";
            }
            break;


        case 5:
            return 0;


        default:
            std::cout << "Invalid choice!\n\n";
            break;
        }
    }

    return 0;
}
