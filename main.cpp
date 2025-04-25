#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int NUM_RECIPES = 6;


string full_name;
string nickname;
string cookingTimes[NUM_RECIPES] = {
    "1hr 30mins", "2hr", "30mins", "31mins", "45mins", "1hr"
};
string recipes[NUM_RECIPES] = {
    "Uzbek Plov", "Chicken Soup", "Buttermilk Pancakes",
    "Chicken Caesar Salad", "One-Pot Garlic Parmesan Pasta", "Bibimbap"
};

void showMainMenu();
void showDiscoverPage();
int showRecipes();
void registerUser();
void startCooking(string recipe);
void showIngredients(int choice, int servings);
void saveUserToFile(string fullName, string nick);

void showTitleScreen() {
    cout << "======================" << endl;
    cout << "       CookMe         " << endl;
    cout << "======================" << endl;
    cout << "Press Enter to begin...";
    cin.ignore();
    cin.get();
    registerUser();
}

void saveUserToFile(string fullName, string nick) {
    ofstream outFile("users.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Full Name: " << fullName << ", Nickname: " << nick << endl;
        outFile.close();
    } else {
        cout << "Error saving user info.\n";
    }
}

void registerUser() {
    cout << "\nEnter your full name: ";
    getline(cin, full_name);

    while (true) {
        cout << "Enter your nickname: ";
        getline(cin, nickname);

        if (!nickname.empty()) {
            break;
        }
        cout << "Nickname cannot be empty. Please try again.\n";
    }

    saveUserToFile(full_name, nickname);
    cout << "\nWelcome " << nickname << "! Press Enter to start your cooking adventure.";
    showMainMenu();
}

void showMainMenu() {
    int choice = 0;

    while (true) {
        cout << "\n===== Main Menu =====" << endl;
        cout << "1. Explore Recipes" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice (1-2): ";

        if (cin >> choice) {
            if (choice == 1) {
                showDiscoverPage();
                break;
            } else if (choice == 2) {
                cout << "\nThank you for using CookMe. Goodbye!\n";
                break;
            } else {
                cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } else {
            cout << "Invalid input. Please enter a number.\n";
        }
    }
}

void showDiscoverPage() {
    while (true) {
        int recipeChoice = showRecipes();

        if (recipeChoice == -1) {
            continue;
        }

        string chosenRecipe = recipes[recipeChoice - 1];
        int servings = 0;

        while (true) {
            cout << "How many servings do you want to cook (1-10): ";
            if (cin >> servings) {
                if (servings >= 1 && servings <= 10) {
                    break;
                } else {
                    cout << "Please enter a number between 1 and 10.\n";
                }
            } else {
                cout << "Invalid input. Please enter a number.\n";
            }
        }
        
        int startChoice;
        while (true) {
            cout << "\nStep by step mode for " << chosenRecipe << "? (1 = Yes, 2 = No): ";
            if (cin >> startChoice) {
                if (startChoice == 1 || startChoice == 2) {
                    break;
                } else {
                    cout << "Please enter 1 or 2.\n";
                }
            } else {
                cout << "Invalid input. Please enter a number.\n";
            }
        }

        if (startChoice == 1) {
            startCooking(chosenRecipe);
        } else {
            cout << "Returning to main menu...\n";
            showMainMenu();
        }
        break;
    }
}

int showRecipes() {
    cout << "\n--- Recommended Recipes ---" << endl;
    for (int i = 0; i < NUM_RECIPES; i++) {
        cout << i+1 << ". " << recipes[i] << " - " << cookingTimes[i] << endl;
    }

    int choice;
    while (true) {
        cout << "Choose a recipe (1-" << NUM_RECIPES << ") or 0 to return: ";
        if (cin >> choice) {
            if (choice == 0) {
                showMainMenu();
                return -1;
            } else if (choice >= 1 && choice <= NUM_RECIPES) {
                return choice;
            } else {
                cout << "Invalid choice. Please enter a number between 1 and " << NUM_RECIPES << ".\n";
            }
        } else {
            cout << "Invalid input. Please enter a number.\n";
        }
    }
}

void showIngredients(int choice, int servings) {
    cout << "\n----- Ingredients for ";
    switch (choice) {
        case 1: // Uzbek Plov
            cout << "Uzbek plov (Osh) -----\n";
            cout << "For " << servings << " servings:\n";
            cout << "~ " << 1.0/8 * servings << " cups of corn oil\n";
            cout << "~ " << 1.0/8 * servings << " lbs of beef, cubed\n";
            cout << "~ " << 1.0/8 * servings << " lbs of carrot, peeled and juliened\n";
            cout << "~ " << 1.0 * servings << " oz of onions, juliened\n";
            cout << "~ " << 1.0/2 * servings << " cups of rice (rice to water ratio 1:1, rinsed)\n";
            cout << "~ " << 1.0/2 * servings << " cups of water\n";
            cout << "~ " << 1.0/8 * servings << " teaspoons of salt or black pepper to taste\n";
            break;
        case 2: // Chicken Soup
            cout << "Chicken soup -----\n";
            cout << "For " << servings << " servings:\n";
            cout << "~ " << 1.0/5 * servings << " whole chicken(s)\n";
            cout << "~ " << 2.0/5 * servings << " carrots, halved\n";
            cout << "~ " << 2.0/5 * servings << " stalks celery, halved\n";
            cout << "~ " << 1.0/5 * servings << " large onion\n";
            cout << "~ " << 1.0/5 * servings << " teaspoons of chicken bouillon granules\n";
            cout << "~ water to cover\n~ salt and pepper, to taste\n";
            break;
        case 3: // Buttermilk Pancakes
            cout << "Buttermilk pancakes -----\n";
            cout << "For " << servings << " servings:\n";
            cout << "~ " << 1.0/2 * servings << " cups of all-purpose flour\n";
            cout << "~ " << 1.0/2 * servings << " tablespoons of sugar\n";
            cout << "~ " << 1.0/8 * servings << " teaspoons of salt\n";
            cout << "~ " << 1.0/8 * servings << " teaspoons of baking powder\n";
            cout << "~ " << 1.0/8 * servings << " teaspoons of baking soda\n";
            cout << "~ " << 1.0/2 * servings << " cups of buttermilk\n";
            cout << "~ " << 1.0/2 * servings << " egg\n";
            cout << "~ " << 3.0/4 * servings << " tablespoons of unsalted butter, melted\n";
            cout << "~ maple syrup, honey, fruits (optional)\n";
            break;
        case 4: // Chicken Caesar Salad
            cout << "Chicken Caesar salad -----\n";
            cout << "For " << servings << " servings:\n";
            cout << "~ " << 5.0/2 * servings << " oz of farfalle pasta, \"bow-tie\" pasta\n";
            cout << "~ " << 3.0/4 * servings << " chicken breasts\n";
            cout << "~ " << 3.0/4 * servings << " tablespoons of olive oil\n";
            cout << "~ " << 1.0/2 * servings << " heads of romaine lettuce, cut into 1-2 inch pieces\n";
            cout << "~ " << 1.0/4 * servings << " cups of grape tomatoes, cut in half\n";
            cout << "~ " << 1.0/4 * servings << " cups of crouton\n";
            cout << "~ " << 1.0/8 * servings << " cups of Caesar dressing\n";
            cout << "~ salt, to taste\n~ pepper, to taste\n~ Parmesan cheese, to taste\n";
            break;
        case 5: // One-Pot Garlic Parmesan Pasta
            cout << "One-pot garlic Parmesan pasta -----\n";
            cout << "For " << servings << " servings:\n";
            cout << "~ " << 1.0/2 * servings << " tablespoons of unsalted butter\n";
            cout << "~ " << 1.0 * servings << " cloves of garlic, minced\n";
            cout << "~ " << 1.0/2 * servings << " cups of chicken broth\n";
            cout << "~ " << 1.0/4 * servings << " cups of milk\n";
            cout << "~ " << 2.0 * servings << " oz of fettuccine\n";
            cout << "~ " << 1.0/2 * servings << " tablespoons of fresh parsley, chopped\n";
            cout << "~ grated Parmesan cheese\n~ salt, to taste\n~ pepper, to taste\n";
            break;
        case 6: // Bibimbap
            cout << "Chicken bibimbap -----\n";
            cout << "For " << servings << " servings:\n";
            cout << "~ " << 3.0/2 * servings << " cloves of garlic, minced, divided\n";
            cout << "~ " << 1.0 * servings << " teaspoons of fresh ginger, minced\n";
            cout << "~ " << 1.0 * servings << " scallion, thinly sliced\n";
            cout << "~ " << 1.0/8 * servings << " cups of soy sauce\n";
            cout << "~ " << 2.0 * servings << " tablespoons of sesame oil\n";
            cout << "~ " << 1.0/2 * servings << " tablespoons of mirin\n";
            cout << "~ " << 1.0/2 * servings << " tablespoons of light brown sugar\n";
            cout << "~ " << 1.0/2 * servings << " lbs of boneless, skinless chicken thighs, sliced into 1/2 inch strips\n";
            cout << "~ " << 2.0 * servings << " cups of fresh spinach\n";
            cout << "~ " << 1.0 * servings << " large carrots\n";
            cout << "~ " << 4.0 * servings << " oz of shiitake mushroom, thinly sliced\n";
            cout << "~ " << 1.0/2 * servings << " tablespoons unsalted butter\n";
            cout << "~ " << 1.0 * servings << " large egg\n";
            cout << "~ salt and black pepper to taste\n";
            cout << "~~~ For serving ~~~\n~ sushi rice, cooked\n~ Persian cucumber, thinly sliced\n";
            cout << "~ " << 1.0/2 * servings << " cups of cabbage kimchi\n";
            break;
        default:
            cout << "Recipe not found.\n";
    }
}

void startCooking(string recipe) {
    cout << "\n--- Cooking Steps for " << recipe << " ---\n";

    if (recipe == "Uzbek Plov") {
        cout << "Step 1\nIngredient Preparation:\n1. Wash the rice under the tap until clear, cover with cold water and let it soak for a while.\n2. Cut the meat with bones into match-box pieces.\n3. Cut the carrots into 0.5x0.5 cm thick sticks.\n4. Slice onions into thin rings or half-rings.\n5. Clean heads of garlic from the remains of roots and dirt.\n\n";
        cout << "Step 2\nHeat oil in the cauldron or Dutch oven on a very high flame, deep-fry meat until golden-brown, in 3-4 batches. Fry the onions until golden, add meat to the cauldron, stir well to prevent onion from burning. Add carrot, stir from time to time, until it starts to wilt and browns a little (15-20 min). Add 2/3 of the cumin - rub it in your palms a little to release flavor, stir gently to keep carrot from breaking.\n\n";
        cout << "Step 3\nDrain rice well, place it on top the meat and vegetables in one layer, stick the garlic and whole chilies in it, and carefully pour boiling water over it (place a spoon or ladle on top of the rice to keep the rice layer from washing away). Cover the rice with about 2 cm of water, let it boil. Add salt to make the water a bit over-salted. When water will go down the rice, reduce the heat a bit, keeping it boils rapidly. Check when it will evaporate and absorb into rice completely - rice should remain rather al dente. Make holes in the rice to the bottom of a vessel to check the water level.\n\n";
        cout << "Step 4\nReduce heat to absolute minimum, cover tightly with the lid and let it steam 20 minutes. Turn off the heat, remove the garlic and chilies on the separate plate. Carefully mix rice with meat and carrots, if the rice tastes a bit bland add some salt, mix and let it stand for 5 minutes. Pile the plov on a big warmed plate and serve with garlic, chilies and plain thinly sliced tomato-sweet onions-chili-salt salad.\n";
    } else if (recipe == "Chicken Soup") {
        cout << "Step 1\nGather all ingredients.\n\n";
        cout << "Step 2\nPlace chicken, carrots, celery, and onion in a large soup pot; add enough cold water to cover. Bring to a boil over medium heat; reduce heat to low and simmer, uncovered, until meat falls off of the bone, about 90 minutes. Skim off foam every so often, as needed.\n\n";
        cout << "Step 3\nRemove chicken from the pot and let sit until cool enough to handle; chop meat into pieces, and discard skin and bones.\n\n";
        cout << "Step 4\nStrain out vegetables, reserving the stock; rinse the soup pot and return the stock to the pot. Chop vegetables into smaller pieces; return chopped chicken and vegetables to the pot.\n\n";
        cout << "Step 5\nWarm soup until heated through; season with salt, pepper, and chicken bouillon to taste.\n";
    } else if (recipe == "Buttermilk Pancakes") {
        cout << "Step 1\nIn a bowl, add the flour, sugar, salt, baking powder, and the baking soda, and whisk to combine.\n\n";
        cout << "Step 2\nIn a bowl or measuring cup, whisk the buttermilk, eggs, and melted butter until smooth.\n\n";
        cout << "Step 3\nAdd the buttermilk mixture to the dry ingredients, gently incorporating with a spatula. Make sure not to overmix, as that will result in dense pancakes.\n\n";
        cout << "Step 4\nAdd the butter to the pan over medium low heat. Once the butter begins to bubble, add 1/3 cup of batter to the pan.\n\n";
        cout << "Step 5\nCook until the top side begins to bubble and the bottom is golden brown. Flip the pancake and cook until the underside is golden brown. Repeat with the remaining batter.\n";
    } else if (recipe == "Chicken Caesar Salad") {
        cout << "Step 1\nBoil water, add the pasta, and cook according to package instructions. Drain water, and let the pasta chill.\n\n";
        cout << "Step 2\nMeanwhile, season each of the chicken breasts with 1 Tbsp. olive oil, salt, and pepper.\n\n";
        cout << "Step 3\nGrill for 6 to 8 minutes on each side. Cut the chicken into bite-size pieces.\n\n";
        cout << "Step 4\nIn a large bowl combine pasta, romaine lettuce, tomatoes, chicken, croutons, Parmesan, and Caesar dressing. Toss gently.\n";
    } else if (recipe == "One-Pot Garlic Parmesan Pasta") {
        cout << "Step 1\nHeat unsalted butter in a large skillet over medium high heat. Add garlic and cook, stirring frequently, until fragrant, about 1-2 minutes.\n\n";
        cout << "Step 2\nAdd in the chicken broth, milk, and fettuccine. Season with salt and pepper.\n\n";
        cout << "Step 3\nBring the pot to a boil, then reduce heat and simmer, stirring occasionally, until pasta is cooked through, about 18-20 minutes.\n\n";
        cout << "Step 4\nStir in Parmesan. If the mixture is too thick, add more milk as needed until desired consistency is reached.\n\n";
        cout << "Step 5\nServe immediately, and top with parsley.\n";
    } else if (recipe == "Bibimbap") {
        cout << "Step 1\nIn a shallow dish, combine 2 cloves of garlic, the ginger, 2 thinly sliced scallions, soy sauce, 2 tablespoons sesame oil, mirin, and brown sugar. Whisk to combine. Add the chicken, toss to coat, cover with plastic wrap, and marinate in the refrigerator for 30 minutes.\n\n";
        cout << "Step 2\nBring a large pot of salted water to a boil. Prepare an ice bath in a bowl. Blanch the spinach in boiling water for 30 seconds, then transfer to the ice bath. Drain, transfer to a bowl, and season with 1 teaspoon sesame oil, salt, and pepper.\n\n";
        cout << "Step 3\nIn a medium skillet, heat 1 teaspoon sesame oil over medium heat. Add the carrots and cook until softened (2-3 minutes). Remove and season with salt.\n\n";
        cout << "Step 4\nIn the same skillet, heat 1 tablespoon sesame oil over medium-high heat. Add 1 clove of garlic and cook for 30 seconds until fragrant. Add mushrooms and cook until softened (about 2 minutes). Season with salt and set aside.\n\n";
        cout << "Step 5\nIn the same skillet, heat the remaining 1 tablespoon sesame oil over medium-high heat. Add the marinated chicken and sauté, stirring occasionally, until cooked through (about 5 minutes).\n\n";
        cout << "Step 6\nHeat a nonstick pan over medium-high heat. Melt butter, crack eggs into the pan, and cook until whites are firm with golden edges and yolks are runny (or to desired doneness).\n\n";
        cout << "Step 7\nDivide rice among bowls. Top with chicken, kimchi, scallions, carrots, spinach, mushrooms, cucumbers, and fried eggs.\nEnjoy immediately, mixing all ingredients together before eating. Drizzle with gochujang (Korean chili paste) or extra sesame oil for added flavor.\n";
    } else {
        cout << "Recipe steps not found.\n";
    }

    int again;
    while (true) {
        cout << "\nWould you like to cook another dish? (1 = Yes, 2 = Exit): ";
        if (cin >> again) {
            if (again == 1) {
                showDiscoverPage();
                break;
            } else if (again == 2) {
                cout << "Thank you for cooking with us. Bon Appetit!\n";
                break;
            } else {
                cout << "Please enter 1 or 2.\n";
            }
        } else {
            cout << "Invalid input. Please enter a number.\n";
        }
    }
}

int main() {
    showTitleScreen();
    return 0;
}
