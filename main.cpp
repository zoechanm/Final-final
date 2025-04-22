Munisa fed 2, [4/22/2025 11:21 PM]
#include <iostream>
#include <string>
using namespace std;

string full_name;
string nickname;
string cookingTimes[6] = {
    "1hr 30mins",
    "2hr",
    "30mins",
    "31mins",
    "45mins",
    "1hr"
};
string recipes[6] = {
    "Uzbek Plov",
    "Chicken Soup",
    "Buttermilk Pancakes",
    "Chicken Caesar Salad",
    "One-Pot Garlic Parmesan Pasta",
    "Bibimbap",
    };

void showMainMenu();
void showDiscoverPage();
int showRecipes();
void registerUser();
void startCooking(string recipe);
void showIngredients( int choice, int servings);

void showTitleScreen() {
    cout << "======================" << endl;
    cout << "       CookMe         " << endl;
    cout << "======================" << endl;
    cin.ignore();
    cin.get();
    registerUser();
}

void registerUser() {
    cout<<"Enter your full name: ";
    getline(cin, full_name);
    cout<<"Enter your nickname: ";
    getline(cin, nickname);
    cout<<"Welcome "<<nickname<<"! Press the start button and became a chef.";
    cin.get();
    showMainMenu();
}

void showMainMenu() {
    int choice;
    cout<<"Would you like to start cooking?\n";
    cout<<"1. Explore "<<endl;
    cout<<"2. Exit"<<endl;
    cout<<"Enter your choice: "; cin>>choice;

    if (choice == 1) {
        showDiscoverPage();
    }else {
        cout<<"Thank you for using CookMe. Goodbye!";
    }
}
void showDiscoverPage() {
    int recipeChoice = showRecipes();
    if (recipeChoice >= 1 && recipeChoice <= 6) {
        string chosenRecipe = recipes[recipeChoice - 1];

        int servings;
        cout << "How many servings do you want to cook: ";
        cin >> servings;

        showIngredients(recipeChoice, servings);

        int startChoice;
        cout << "\nStep by step mode" << chosenRecipe << "? (1 = Yes, 2 = No): ";
        cin >> startChoice;

        if (startChoice == 1) {
            startCooking(chosenRecipe);
        } else {
            cout << "Returning to main menu...\n";
            showMainMenu();
        }

    } else {
        cout << "Invalid choice. Returning to main menu.\n";
        showMainMenu();
    }
}

int showRecipes(){
    cout<<endl<<"--- What we recommend for you to cook ---"<<endl;

    for (int i = 0; i < 6; i++) {
        cout<<i+1<<". "<<recipes[i]<<" - "<<cookingTimes[i]<<endl;
    }

    int choice;
    cout<<"Choose a recipe by entering a number(1-6): "<<endl;
    cin>>choice;

    if (choice >= 1 && choice <= 6) {
        return choice; // just return the choice
    } else {
        cout << "Invalid selection. Returning to main menu.\n";
        showMainMenu();
        return -1;
    }
}

Munisa fed 2, [4/22/2025 11:21 PM]
void showIngredients( int choice, int servings) {
    cout << "\n -----Ingredients for ";
    switch (choice) {
        case 1: //Osh
            cout << "Uzbek plov (Osh)-----\n";
            cout << "For " << servings << " servings:\n";
            cout << "~" << 1.0/8 * servings << " cups of corn oil\n";
            cout << "~" << 1.0/8 * servings << " lbs of beef, cubed\n";
            cout << "~" << 1.0/8 * servings << " lbs of carrot, peeled and juliened\n";
            cout << "~" << 1.0 * servings << " oz of onions, juliened\n";
            cout << "~" << 1.0/2 * servings << " cups of rice(rice to water ratio 1:1 rinsed\n";
            cout << "~" << 1.0/2 * servings << " cups of water\n";
            cout << "~" << 1.0/8 * servings << " teaspoons of salt or black pepper to taste\n";
        break;
        case 2:
            cout << "Chicken soup----- \n";
            cout << "For " << servings << " servings:\n";
            cout << "~" << 1.0/5 * servings << " whole chicken(s)\n";
            cout << "~" << 2.0/5 * servings << " carrots, halved\n";
            cout << "~" << 2.0/5 * servings << " stalks celery, halved\n";
            cout << "~" << 1.0/5 * servings << " large onion\n";
            cout << "~" << 1.0/5 * servings << " teaspoons of chicken bouillon granules\n";
            cout << "~" << " water to cover\n~ salt and pepper, to taste\n";
        break;
        case 3:
            cout << "Chicken ceaser salad----- \n";
            cout << "For " << servings << " servings:\n";
            cout << "~" << 5.0/2 * servings << " oz of farfalle pasta, \"bow-tie\" pasta\n";
            cout << "~" << 3.0/4 * servings << " chicken breasts\n";
            cout << "~" << 3.0/4 * servings << " tablespoons of olive oil\n";
            cout << "~" << 1.0/2 * servings << " heads of romaine lettuce, cut into 1-2 inch pieces\n";
            cout << "~" << 1.0/4 * servings << " cups of grape tomatoes, cut in half\n";
            cout << "~" << 1.0/4 * servings << " cups of crouton\n";
            cout << "~" << 1.0/8 * servings << " cups of caesar dressing\n";
            cout << "~" << " salt, to taste\n~ pepper, to taste\n~ parmesan cheese, to taste\n";
        break;
        case 4:
            cout << "Buttermilk pancakes----- \n";
            cout << "For " << servings << " servings:\n";
            cout << "~" << 1.0/2 * servings << " cups of all-purpose flour\n";
            cout << "~" << 1.0/2 * servings << " tablespoons of sugar\n";
            cout << "~" << 1.0/8 * servings << " teaspoons of salt\n";
            cout << "~" << 1.0/8 * servings << " teaspoons of baking powder\n";
            cout << "~" << 1.0/8 * servings << " teaspoons of baking soda\n";
            cout << "~" << 1.0/2 * servings << " cups of buttermilk\n";
            cout << "~" << 1.0/2 * servings << " egg\n";
            cout << "~" << 3.0/4 * servings << " tablespoons of unsalted butter, melted\n";
            cout << "~" << " maple syrup, honey, fruits (optional)\n";
        break;
        case 5:
            cout << "One-pot garlic parmesan pasta----- \n";
            cout << "For " << servings << " servings:\n";
            cout << "~" << 1.0/2 * servings << " tablespoons of unsalted butter\n";
            cout << "~" << 1.0 * servings << " cloves of garlic, minced\n";
            cout << "~" << 1.0/2 * servings << " cups of chicken broth\n";
            cout << "~" << 1.0/4 * servings << " cups of milk\n";
            cout << "~" << 2.0 * servings << " oz of fettuccine\n";
            cout << "~" << 1.0/2 * servings << " tablespoons of fresh parsley, chopped\n";
            cout << "~" << " graded parmesan cheese\n~ salt, to taste\n~ pepper, to taste\n";
        break;
        case 6:
            cout << "Chicken bibimbap----- \n";
            cout << "For " << servings << " servings:\n";
            cout << "~" << 3.0/2 * servings << " cloves of garlic, minced, divided\n";
            cout << "~" << 1.0 * servings << " teaspoons of fresh ginger, minced\n";
cout << "~" << 1.0 * servings << " scallion, thinly sliced\n";

Munisa fed 2, [4/22/2025 11:21 PM]
cout << "~" << 1.0/8 * servings << " cups of soy sauce\n";
            cout << "~" << 2.0 * servings << " tablespoons of sesame oil\n";
            cout << "~" << 1/2 * servings << " tablespoons of mirin\n";
            cout << "~" << 1.0/2 * servings << " tablespoons of light brown sugar\n";
            cout << "~" << 1.0/2 * servings << " lbs of boneless, skinless chicken thighs, sliced into 1/2 inch strips\n";
            cout << "~" << 2.0 * servings << " cups of fresh spinach\n";
            cout << "~" << 1.0 * servings << " large carrots\n";
            cout << "~" << 4.0 * servings << " oz of shiitake mushroom, thinly sliced\n";
            cout << "~" << 1.0/2 * servings << " tablespoons unsalted butter\n";
            cout << "~" << 1.0 * servings << " large egg\n";
            cout << "~" << " salt and black pepper to taste\n";
            cout << "~~~For serving~~~\n~ sushi rice, cooked\n~ persian cucumber, thinly sliced\n";
            cout << "~" << 1.0/2 * servings << " cups of cabbage kimchi\n";
        break;
        default:
            cout<<"Recipe not fount.\n";
    }
}
void startCooking(string recipes) {
        cout<<"\n--- Cooking Steps for " << recipes << " ---\n";

    if (recipes == "Uzbek Plov") {
        cout<<"Step1"<<endl<<"Ingredient Preparation: 1. Wash the rice under the tap until clear, cover with cold water and let it soaks for a while. 2. Cut the meat with bones into match-box pieces. 3. Cut the carrots into 0.5x0.5 cm thick sticks. 4. Slice onions into thin rings or half-rings. 5. Clean heads of garlic from the remains of roots and dirt."<<endl<<"Step 2"<<endl<<"Heat oil in the cattle or dutch oven on a very high flame, deep-fry meat until golden-brown, in 3-4 batches. Fry the onions until golden, add meat to the cattle, stir well to prevent onion from burning. Add carrot, stir from time to time, until it starts to wilt and browns a little (15-20 min). Add 2/3 of the cumin - rub it in your palms a little to release flavor, stir gentliy to keep carrot from broking."<<endl<<"Step 3"<<endl<<"Drain rice well, place it on top the meat and vegs in one layer, stick the garlic and whole chillies in it, and carefully pour boiling water over it (place a spoon or ladle on top of the rice to keep the rice layer from washaway). Cover the rice with about 2 cm of water, let it boil. Add salt to make the water a bit over-salted. When water will go down the rice, reduce the gas a bit, keeping it boils rapidly. Check when it will evaporate and absorb into rice completely - rice should remain rather al dente. Make a holes in the rice to the bottom of a vessel to check the water level. \n4. Reduce gas to absolute min, cover tightly with the lid and let it steam 20 minutes. Turn of the heat, remove the garlic and chillies on the separate plate. Carefully mix rice with meat and carrots, if the rice tastes a bit blind add some salt, mix and let it stand for 5 minutes. Pile the plov on a big warmed plate and serve with garlic, chilies and plain thinly sliced tomato-sweet onions-chili-salt salad.";
    } else if (recipes == "Chicken Soup") {
cout<<"Step 1"<<endl<<"Gather all ingredients."<<endl<<"Step 2"<<endl<<"Place chicken, carrots, celery, and onion in a large soup pot; add enough cold water to cover. Bring to a boil over medium heat; reduce heat to low and simmer, uncovered, until meat falls off of the bone, about 90 minutes. Skim off foam every so often, as needed."<<endl<<"Step 3"<<endl<<"Remove chicken from the pot and let sit until cool enough to handle; chop meat into pieces, and discard skin and bones."<<endl<<"Step 4"<<endl<<"Strain out vegetables, reserving the stock; rinse the soup pot and return the stock to the pot. Chop vegetables into smaller pieces; return chopped chicken and vegetables to the pot."<<endl<<"Step 5"<<endl<<"Warm soup until heated through; season with salt, pepper, and chicken bouillon to taste";
    } else if (recipes == "Buttermilk Pancakes") {

Munisa fed 2, [4/22/2025 11:21 PM]
cout<<"Step 1"<<endl<<"In a bowl, dd the flour, sugar, salt, baking powder, and the baking soda, and whisk to combine"<<endl<<"Step 2"<<endl<<"In a bol of measuring cup, whisk the buttermilk, eggs, and melted butter until smooth"<<"Step 3"<<endl<<"Add the buttermilk mixture to the dry ingredients, gently incorporating with a spatula. Make sure not to overmix,as that will result in dense pancakes."<<endl<<"Step 4"<<endl<<"Add the butter to the pan over medium low heat. Once the butter begins to bubble, add 1/3 cup of batter to the pan."<<"Step 5"<<endl<<"Cook until the top side begins to bubble and the bottom is golden brown.Flip the pancake and cook until the underside is golden brown. Repeat with the remaining batter.";
    } else if ( recipes == "Chicken Caesar Salad") {
        cout<<"Step 1"<<endl<<"Boil water, add the pasta, and cook according to package instructions. Drain water, and lrt the psta chill."<<endl<<"Step 2"<<"Meanwhile, season each of the chicken breasts with 1 Tbsp. olive oil,salt, and pepper."<<endl<<"Step 3"<<endl<<"Grill for 6 to 8 minutes on each side. Cut the chicken into bite-size pieces"<<endl<<"Step 4"<<endl<<"In a large bowl combine pasta, romaine lettuce, tomatoes,chicken, croutons,parmesan, and Caesar dressing. Toss gently.";
    } else if ( recipes == "One-Pot Garlic Parmesan Pasta") {
        cout<<"Step 1"<<endl<<"Heat unsalted butter in a large skillet over medium high heat. Add garlic and cook, stirring frequently, until fragrant, about 1-2 minutes."<<endl<<"Step 2"<<"Add in the chicken broth, milk, and fettuccine.Season with salt and pepper."<<endl<<"Step 3"<<"Bring the pot to a boil,then reduce heat and simmer, stirring occasionally, until pasta is cooked through, about 18-20 minutes."<<endl<<"Step 4"<<endl<<"Stir in Parmesan.If the mixture is too tick, add more milk as needed until desired consistency is reached."<<endl<<"Step 5"<<endl<<"Serve immediately, and top with parsley.";
    }else if ( recipes == "Bibimbap") {

cout<<"In a shallow dish, combine 2 cloves of garlic, the ginger, 2 thinly sliced scallions, soy sauce, 2 tablespoons sesame oil, mirin, and brown sugar. Whisk to combine. Add the chicken, toss to coat, cover with plastic wrap, and marinate in the refrigerator for 30 minutes."<<endl<<"Step 2"<<endl<<"Bring a large pot of salted water to a boil. Prepare an ice bath in a bowl. Blanch the spinach in boiling water for 30 seconds, then transfer to the ice bath. Drain, transfer to a bowl, and season with 1 teaspoon sesame oil, salt, and pepper."<<endl<<"Step 3"<<endl<<"In a medium skillet, heat 1 teaspoon sesame oil over medium heat. Add the carrots and cook until softened (2-3 minutes). Remove and season with salt."<<endl<<"Step 4"<<endl<<"In the same skillet, heat 1 tablespoon sesame oil over medium-high heat. Add 1 clove of garlic and cook for 30 seconds until fragrant. Add mushrooms and cook until softened (about 2 minutes). Season with salt and set aside"<<endl<<"Step 5"<<endl<<"In the same skillet, heat the remaining 1 tablespoon sesame oil over medium-high heat. Add the marinated chicken and sauté, stirring occasionally, until cooked through (about 5 minutes)."<<endl<<"Step 6"<<endl<<"Heat a nonstick pan over medium-high heat. Melt butter, crack eggs into the pan, and cook until whites are firm with golden edges and yolks are runny (or to desired doneness)"<<endl<<"Step 7"<<endl<<"Divide rice among bowls. Top with chicken, kimchi, scallions, carrots, spinach, mushrooms, cucumbers, and fried eggs."<<"Enjoy immediately, mixing all ingredients together before eating.Drizzle with gochujang (Korean chili paste) or extra sesame oil for added flavor.";
    }else {
        cout<<"Recipe steps are not found";
    }
    cout << "\nWould you like to cook another dish? (1 = Yes, 2 = Exit): ";
    int again;
    cin >> again;

    if (again == 1) {
        showDiscoverPage();
    } else {
        cout << "Thank you for cooking with us. Bon Appétit!\n";
    }
}
int main() {
    showTitleScreen();
    return 0;
}
