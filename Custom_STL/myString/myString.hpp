
#include <cstddef>
#include <stdexcept>

namespace ARahimovic
{

	class myString
	{
		public :
			using iterator = char*; 
			using const_iterator = const char*;


			myString();
			explicit myString(const char* txt);
			myString(const myString& other);
			myString& operator=(const myString& other);
			myString(myString&& other) noexcept;
			myString& operator=(myString&& other) noexcept;
			~myString() noexcept;

			constexpr std::size_t size() const noexcept {return buffer_size;}
			constexpr std::size_t length() const noexcept {return buffer_size;}
			constexpr std::size_t capacity() const noexcept {return buffer_capacity;}
			bool empty() const noexcept;
			const char* c_str() const noexcept;
			
			//element access non-const
			char& operator[](std::size_t pos);
			char& at(std::size_t pos);
			char& front();
			char& back();

			//element access const
			const char& operator[](std::size_t pos) const ;
			const char& at(std::size_t pos) const;
			const char& front() const;
			const char& back() const;

			void reserve(std::size_t new_cap);
			void clear() noexcept;
			void shrink_to_fit();
			void push_back(char c);
			void pop_back();

			//iterators 
			iterator begin() noexcept {return buffer_ptr;};
			iterator end() noexcept {return buffer_ptr + buffer_size;}
			const_iterator begin() const {return buffer_ptr;} 
			const_iterator end() const {return buffer_ptr + buffer_size;}
			const_iterator cbegin() const {return buffer_ptr;}
			const_iterator cend() const {return buffer_ptr +  buffer_size;}

			void append(const char* txt);

			//operators 
			myString& operator+=(const myString& other);

		private :

			char *buffer_ptr{nullptr};
			std::size_t buffer_size{0};
			std::size_t buffer_capacity{0};
							

	};

}
