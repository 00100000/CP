struct Node {
	long long lo, hi;
	Node* right = nullptr;
	Node* left = nullptr;
	long long lazy = 0, sum = 0;

	Node(long long r_lo, long long r_hi) {
		lo = r_lo;
		hi = r_hi;
	}
	void build(long long r_lo, long long r_hi, vector<long long>& vals) {
		if (vals.size() <= r_hi) return;
		long long m = (hi + lo) / 2;
		if (r_lo == r_hi) {
			sum = vals[r_hi];
			return;
		}
		left = new Node(lo, m);
		right = new Node(m + 1, hi);
		left->build(lo, m, vals);
		right->build(m + 1, hi, vals);
		sum = left->sum + right->sum;
	}
	void increment(long long r_lo, long long r_hi, long long amt) {
		if (r_lo > hi || r_hi < lo) return;
		if (r_lo <= lo && r_hi >= hi) {
			lazy += amt;
			sum += amt * (hi + 1 - lo);
			return;
		}
		push();
		left->increment(r_lo, r_hi, amt);
		right->increment(r_lo, r_hi, amt);
		sum = right->sum + left->sum;
	}
	void push() {
		if (lazy != 0) {
			left->increment(lo, hi, lazy);
			right->increment(lo, hi, lazy);
			lazy = 0;
		}
	}
	long long rangeSum(long long r_lo, long long r_hi) {
		if (lo > r_hi || hi < r_lo) return 0;
		if (lo >= r_lo && hi <= r_hi) return sum;
		push();
		long long rsum = 0;
		if (left != nullptr) rsum += left->rangeSum(r_lo, r_hi);
		if (right != nullptr) rsum += right->rangeSum(r_lo, r_hi);
		return rsum;
	}
};
