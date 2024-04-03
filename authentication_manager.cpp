/*
* authentication manager(time_to_live)
* generateToken(tokenId, current_time)
* renew(tokenId, current_time)
* countUnexpiredTokens(int current_time)
*/
/*
* use two hash maps, one is to store the mapping from the token to the time to expire.
* the other is to store the mapping from the time-to-expire to the list of tokens
* for generate token, we can check if the token exists or not, if not, we add the token to the two maps.
* for renew, we update the time-to-expire in the token map, and move the token to the appropriate bucket in the time-to-expire map.
* for count unexpired tokens, we can just leverage the upbound function on map to find the iterator where the expired time starts to bigger than the current time.
*/

#include <cstdio>
#include<map>
#include <string>
#include <unordered_set>
using namespace std;
class AuthenticationManager {
public:
    AuthenticationManager(int time_to_expire) {
        this->time_to_expire = time_to_expire;
    }

    void GenerateToken(string tokenId, int current_time) {
        if (this->token2time.contains(tokenId)) return;
        this->token2time[tokenId] = current_time + this->time_to_expire;
        if (!this->time2token.contains(this->token2time[tokenId])) {
            this->time2token[this->token2time[tokenId]]= { tokenId };
        }
        else
        {
            this->time2token[this->token2time[tokenId]].insert(tokenId); //we should consider a list in case there are multiple token sharing same expired time. 
        }
    }

    void Renew(string tokenId, int current_time) {
        if (!this->token2time.contains(tokenId)) return;
        this->time2token[this->token2time[tokenId]].erase(tokenId);
        if (this->time2token[this->token2time[tokenId]].size() == 0) {
            this->time2token.erase(this->token2time[tokenId]);
        }
        this->token2time[tokenId] = current_time + this->time_to_expire;
        if (!this->time2token.contains(this->token2time[tokenId])) {
            this->time2token[this->token2time[tokenId]] = { tokenId };
        }
        else
        {
            this->time2token[this->token2time[tokenId]].insert(tokenId);
        }
    }

    int CurrentUnexpired(int current_time) {
        auto it = this->time2token.lower_bound(current_time);
        int counter = 0;
        while (it != this->time2token.end()) counter+=(int)it->second.size();
        return counter;
    }
private:
    int time_to_expire = 0;
    map<string, int> token2time;
    map<int, unordered_set<string>> time2token;
};