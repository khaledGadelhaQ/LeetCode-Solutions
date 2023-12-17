class FoodRatings {
public:
    unordered_map<string, set<pair<int,string>> > cuisineRatings; // [Cuisine] => [[rate,food] , [rate,food] , ...]
    unordered_map<string, int> foodRate; // [FOOD] => [Rate]
    unordered_map<string, string> foodCuisine; // [FOOD] => [Cuisine]

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0 ;  i  < (int) foods.size() ; i++){
            cuisineRatings[cuisines[i]].insert({ -ratings[i], foods[i]}); // the negitive sign to reverse the sort of the set
            foodRate[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        // we get the cuisine from the foodCuisine map 
        // we remove this food and its rate from the set in the cuisineRatings map
        // we add the new food and its new rating
        // we update the foodRate with the newRating
        string &cuisine = foodCuisine[food];
        cuisineRatings[cuisine].erase({-foodRate[food], food});
        cuisineRatings[cuisine].insert({-newRating, food});
        foodRate[food] = newRating;
    }
    string highestRated(string cuisine) {
        return begin(cuisineRatings[cuisine])->second;
    }
};
