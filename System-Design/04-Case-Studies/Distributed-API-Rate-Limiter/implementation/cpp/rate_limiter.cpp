
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

class TokenBucket {
private:
    double capacity;
    double tokens;
    double refillRate;

    chrono::steady_clock::time_point lastRefill;

    void refill() {
        auto now = chrono::steady_clock::now();

        chrono::duration<double> elapsed = now - lastRefill;

        double newTokens = elapsed.count() * refillRate;

        tokens = min(capacity, tokens + newTokens);

        lastRefill = now;
    }

public:
    TokenBucket(double maxTokens, double rate)
        : capacity(maxTokens),
          tokens(maxTokens),
          refillRate(rate),
          lastRefill(chrono::steady_clock::now()) {}

    bool allowRequest() {
        refill();

        if (tokens >= 1.0) {
            tokens -= 1.0;
            return true;
        }

        return false;
    }
};

int main() {
    TokenBucket limiter(5, 1.0);

    cout << "API Rate Limiter\n";
    cout << "Token Bucket Algorithm\n\n";

    for (int i = 1; i <= 8; i++) {
        if (limiter.allowRequest()) {
            cout << "Request " << i << ": ALLOWED\n";
        } else {
            cout << "Request " << i << ": BLOCKED (HTTP 429)\n";
        }
    }

    return 0;
}
