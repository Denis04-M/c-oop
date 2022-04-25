#include <map>
#include <iostream>
#include <regex>

using namespace std;

using items = std::multimap<std::string, string>;

auto lookup(const items& items, const std::string& keyword)
    -> std::pair<items::const_iterator, items::const_iterator>
{
    auto p = items.lower_bound(keyword);
    auto q = items.end();
    if (p != q && p->first == keyword) {
        return std::make_pair(p, std::next(p));
    } else {
        auto r = p;
        while (r != q && r->first.compare(0, keyword.size(), keyword) == 0) {
            ++r;
        }
        return std::make_pair(p, r);
    }
}

int main(){
	vector<string> songs {};
	multimap<string, string> music{ };

	music.insert({ "Spitboy", "True Self"});
	music.insert({ "Spitboy", "In Your Face"});
	music.insert({ "Lil Wayne ", "In Your Face"});
	music.insert({ "Chaos UK", "In Your Face"});
	music.insert({ "Chaos UK", "King for a Day"});
	music.insert({ "UB40", "Johnny Too Bad"});
	music.insert({ "UB40", "Red Red Wine"});
	music.insert({ "Neil Diamond", "Red Red Wine"});
	music.insert({ "Incubus", "Admiration"});
	music.insert({ "Johnboy", "Admiration"});
	music.insert({ "Jawbreaker", "Kiss the Bottle"});
	music.insert({ "Minor Threat", "Straight Edge"});
	music.insert({ "Bikini Kill", "Rebel Girl"});
	music.insert({ "MC 900 Foot Jesus", "Killer Inside Me"});
	music.insert({ "Sonic Youth", "Kill Yr Idols"});
	music.insert({ "Hüsker Dü", "Eight Miles High"});
	music.insert({ "Butch Hancock", "One Kiss"});
	music.insert({ "Butch Hancock", "Already Gone"});
	music.insert({ "The Clash k", "Complete Control"});
	
	cout << "Key\tElement\n";
	for (auto itr = music.begin(); itr != music.end(); ++itr) {
		cout << itr->first << '\t' << itr->second << '\n';
	}

    cout<<"\n"<<"Enter keyword"<<"\n";
    string keyword;
    cin>> keyword;

    lookup(music, keyword);

	return 0;
}