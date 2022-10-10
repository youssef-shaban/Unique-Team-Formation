#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;


struct Member{
    int id;
    string name;
    vector<Member*> history;
    Member(int id, string name){
       this->id=id;
       this->name=name;
    }
};

void addHist(vector<Member*> team ){
    int size= team.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            team[i]->history.push_back(team[j]);
    }
}
bool workTogether(Member *a,vector<Member*> b){
    int size= a->history.size();
    for(int i=0;i<b.size();i++)
        if(a->id==b[i]->id) return true;
    for(int i=0;i<size;i++){
        for(int j=0;j<b.size();j++)
            if(a->history[i]->id==b[j]->id) return true;
    }
    return false;
}
bool inTeam(Member* a, vector<vector<Member*>> all_teams){
    for(int i=0;i<all_teams.size();i++){
        for(int j=0;j<all_teams[i].size();j++)
            if(a->id==all_teams[i][j]->id) return true;
    }
    return false;
}

void teamFormation(vector<Member*> all_members, int number_of_teams, int number_of_members, default_random_engine rng){
    vector<Member*> all_choices(all_members);

    std::shuffle(std::begin(all_choices), std::end(all_choices), rng);
//    std::shuffle(std::begin(all_choices), std::end(all_choices), rng);
    vector<vector<Member*>> all_teams;
    for(int i =0;i<number_of_teams;i++){
        vector<Member*> team;
        for(int j=0;j<all_choices.size();j++){
            if(inTeam(all_choices[j],all_teams)) continue;
            if(team.empty()) {team.push_back(all_choices[j]); continue;}
           if(!workTogether(all_choices[j], team)){
               team.push_back(all_choices[j]);
           }
           if(team.size()==number_of_members){
               addHist(team);
               for(int k=0;k<team.size();k++){
                   cout<<team[k]->name<<" | ";
                    all_teams.push_back(team);
               }
               break;
           }
        }
        cout<<endl;
    }
cout<<endl;
}
int main() {

    vector<Member*> team= {
            new Member(1,"Kamel Mohammed"),
            new Member(2,"Youssef Shaaban"),
            new Member(3,"Romaisaa Sherif"),
            new Member(4,"Abdelrahman Yasser"),
            new Member(5,"Diaa Badr"),
            new Member(6,"Maryam Megahed"),
            new Member(7,"Abdelrahman Saeed"),
            new Member(8,"Saeed El-Sayed"),
            new Member(9,"Zeyad Amr"),
            new Member(10,"Ahmed Abd Elraouf"),
            new Member(11,"Omar Anwar"),
            new Member(12,"Mo'men Mohamed"),
            new Member(13,"Omar Saad"),
            new Member(14,"Arwa Essam"),
            new Member(15,"Mazen Tarek"),
            new Member(16,"Neven Mohamed"),


    };
    default_random_engine rng;
    rng.seed(chrono::system_clock::now().time_since_epoch().count());
    teamFormation(team, 4,4,rng);
    teamFormation(team, 4,4,rng);
    teamFormation(team, 4,4,rng);
    teamFormation(team, 4,4,rng);
    teamFormation(team, 4,4,rng);
}
