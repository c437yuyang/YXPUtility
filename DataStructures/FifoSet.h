#pragma once
#include <unordered_map>
#include <vector>
namespace yxp_utility {
	template<class key_type, typename container_type = std::vector<key_type>> //default container is
	class FifoSet {
	public:
		typedef typename container_type::iterator iterator_type;

		FifoSet() = default;

		iterator_type begin() {
			return data_.begin();
		}

		iterator_type end() {
			return data_.end();
		}

		iterator_type find(const key_type&key) {
			if (!contains(key)) {
				return data_.end();
			}
			return data_.begin() + data_dict_[key];
		}

		bool contains(const key_type&key) {
			return data_dict_.find(key) != data_dict_.end();
		}

		/// <summary>
		/// 记录的是当前key第一次出现的位置
		/// </summary>
		void insert(const key_type&key) {
			if (!contains(key)) {
				data_.push_back(key);
				data_dict_.insert({ key ,data_.size() - 1 });
			}
		}

		/// <summary>
		/// 但是删除的时间复杂度是O(n)，需要遍历所有的桶，全部下标减一,并且vector也需要移动元素
		/// </summary>
		void erase(const key_type&key) {
			if (contains(key)) {
				size_t idx = data_dict_[key];
				data_.erase(data_.begin() + idx);
				data_dict_.erase(key);
				for (auto it = data_dict_.begin(); it != data_dict_.end(); ++it) {
					if (it->second > idx) {
						--(it->second);
					}
				}
			}
		}

	private:
		container_type data_;
		std::unordered_map<key_type, size_t> data_dict_;
	};
}
