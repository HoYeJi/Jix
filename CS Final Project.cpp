#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a recipe
struct Recipe {
    string name;
    string ingredients;
    string steps;
};

// Function prototypes
void createRecipe(vector<Recipe>& recipes);
void viewRecipes(const vector<Recipe>& recipes);
void updateRecipe(vector<Recipe>& recipes);
void deleteRecipe(vector<Recipe>& recipes);

int main() {
    vector<Recipe> recipes; // Array to store recipes
    int choice;

    do {
        // Display menu
        cout << "\n=== Recipe Manager ===\n";
        cout << "1. Add Recipe\n";
        cout << "2. View Recipes\n";
        cout << "3. Update Recipe\n";
        cout << "4. Delete Recipe\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        // Process user choice
        switch (choice) {
            case 1:
                createRecipe(recipes);
                break;
            case 2:
                viewRecipes(recipes);
                break;
            case 3:
                updateRecipe(recipes);
                break;
            case 4:
                deleteRecipe(recipes);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new recipe
void createRecipe(vector<Recipe>& recipes) {
    Recipe newRecipe;
    cout << "\nEnter recipe name: ";
    getline(cin, newRecipe.name);
    cout << "Enter ingredients (comma-separated): ";
    getline(cin, newRecipe.ingredients);
    cout << "Enter steps: ";
    getline(cin, newRecipe.steps);
    recipes.push_back(newRecipe);
    cout << "Recipe added successfully!\n";
}

// Function to view all recipes
void viewRecipes(const vector<Recipe>& recipes) {
    if (recipes.empty()) {
        cout << "\nNo recipes to display.\n";
        return;
    }
    cout << "\n=== Recipes ===\n";
    for (size_t i = 0; i < recipes.size(); ++i) {
        cout << i + 1 << ". " << recipes[i].name << "\n";
        cout << "   Ingredients: " << recipes[i].ingredients << "\n";
        cout << "   Steps: " << recipes[i].steps << "\n";
    }
}

// Function to update an existing recipe
void updateRecipe(vector<Recipe>& recipes) {
    if (recipes.empty()) {
        cout << "\nNo recipes available to update.\n";
        return;
    }
    int index;
    cout << "\nEnter the recipe number to update: ";
    cin >> index;
    cin.ignore(); // Clear input buffer

    if (index < 1 || index > recipes.size()) {
        cout << "Invalid recipe number.\n";
        return;
    }

    Recipe& recipe = recipes[index - 1];
    cout << "\nUpdating recipe: " << recipe.name << "\n";
    cout << "Enter new ingredients (leave empty to keep current): ";
    string newIngredients;
    getline(cin, newIngredients);
    if (!newIngredients.empty()) recipe.ingredients = newIngredients;

    cout << "Enter new steps (leave empty to keep current): ";
    string newSteps;
    getline(cin, newSteps);
    if (!newSteps.empty()) recipe.steps = newSteps;

    cout << "Recipe updated successfully!\n";
}

// Function to delete a recipe
void deleteRecipe(vector<Recipe>& recipes) {
    if (recipes.empty()) {
        cout << "\nNo recipes available to delete.\n";
        return;
    }
    int index;
    cout << "\nEnter the recipe number to delete: ";
    cin >> index;
    cin.ignore(); // Clear input buffer

    if (index < 1 || index > recipes.size()) {
        cout << "Invalid recipe number.\n";
        return;
    }

    recipes.erase(recipes.begin() + index - 1);
    cout << "Recipe deleted successfully!\n";
}