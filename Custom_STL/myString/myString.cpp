#include "myString.hpp"
#include <cstring>

namespace ARahimovic
{

    myString::myString(): buffer_size(0), buffer_capacity(0){
        buffer_ptr = new char[1]{'\0'};
    }

    myString::myString(const char* txt)
    {
        if (txt == nullptr)
            throw std::invalid_argument("txt is nullptr");

        buffer_size = std::strlen(txt);
        buffer_capacity = buffer_size;
        buffer_ptr = new char[buffer_size + 1];
        std::memcpy(buffer_ptr, txt, buffer_size + 1);
    }

    myString::myString(const myString& other) : buffer_capacity(other.buffer_capacity), buffer_size(other.buffer_size)
    {
        buffer_ptr = new char[buffer_size + 1];
        std::memcpy(buffer_ptr, other.buffer_ptr, buffer_size + 1);
    }

    myString& myString::operator=(const myString& other)
    {
        if (this == &other)
            return *this;

        char* new_buffer = nullptr;
        if (other.buffer_ptr != nullptr)
        {
            new_buffer = new char[other.buffer_size + 1];
            std::memcpy(new_buffer, other.buffer_ptr, other.buffer_size + 1);
        }

        delete[] buffer_ptr;
        buffer_ptr = new_buffer;
        buffer_size = other.buffer_size;
        buffer_capacity = other.buffer_capacity;
        return *this;
    }

    myString::myString(myString&& other) noexcept
    {
        buffer_ptr = other.buffer_ptr;
        buffer_size = other.buffer_size;
        other.buffer_ptr = nullptr;
        other.buffer_size = 0;
    }

    myString& myString::operator=(myString&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete[] buffer_ptr;

        buffer_ptr = other.buffer_ptr;
        buffer_size = other.buffer_size;
        other.buffer_ptr = nullptr;
        other.buffer_size = 0;
        return *this;
    }

    myString::~myString() noexcept
    {
        delete[] buffer_ptr;
    }

    bool myString::empty() const noexcept {return buffer_size == 0;}
    const char* myString::c_str() const noexcept {return buffer_ptr; }
    
    //element access non-const
    char& myString::operator[](std::size_t pos){return buffer_ptr[pos];}
    char& myString::at(std::size_t pos)
    {
        if(pos >= buffer_size)
            throw std::out_of_range("pos out of range");
        return buffer_ptr[pos];
    }

    char& myString::front(){return buffer_ptr[0];}
    char& myString::back(){return buffer_ptr[buffer_size - 1];}
    
    //element access const
    const char& myString::operator[](std::size_t pos) const {return buffer_ptr[pos];}
    const char& myString::at(std::size_t pos) const
    {
        if(pos >= buffer_size)
            throw std::out_of_range("pos out of range");
        return buffer_ptr[pos];
    }

    const char& myString::front() const{return buffer_ptr[0];}
    const char& myString::back() const {return buffer_ptr[buffer_size - 1];}


    void myString::reserve(std::size_t new_cap)
    {
        if(new_cap <= buffer_capacity)
            return;

        char* new_buffer = new char[new_cap + 1];
        std::memcpy(new_buffer, buffer_ptr, buffer_size + 1);
        delete[] buffer_ptr;
        buffer_ptr = new_buffer;
        buffer_capacity = new_cap;
    }

    void myString::clear() noexcept 
    {
        buffer_size = 0;
        if (buffer_ptr != nullptr)
        {
            buffer_ptr[0] = '\0'; 
        }
    }

    void myString::shrink_to_fit() 
    {
        if(buffer_size == buffer_capacity)
            return ;

        char* new_buffer = new char[buffer_size + 1];
        std::memcpy(new_buffer, buffer_ptr, buffer_size + 1);
        delete[] buffer_ptr;
        buffer_ptr = new_buffer;
        buffer_capacity= buffer_size;
    }

    void myString::push_back(char c)
    {
        if(buffer_size == buffer_capacity)
        {
            std::size_t new_cap = (buffer_capacity == 0) ? 8 : static_cast<std::size_t>(buffer_capacity * 1.5);
            if (new_cap <= buffer_capacity)
                new_cap = buffer_capacity + 1;
            reserve(new_cap);
        }

        buffer_ptr[buffer_size] = c;
        buffer_size++;
        buffer_ptr[buffer_size] = '\0';
    }

    void myString::pop_back()
    {
        if(empty())
            return;

        buffer_ptr[--buffer_size] = '\0';
    }
    
    void myString::append(const char* txt)
    {
        if( txt == nullptr)
            throw std::invalid_argument("myString::append : txt is nullptr");

        auto txt_size = std::strlen(txt);
        if(txt_size == 0)
            return;

        auto new_size = txt_size + buffer_size;
        if (new_size > buffer_capacity)
        {
                auto new_cap = (buffer_capacity == 0) ? 8 : static_cast<std::size_t >(buffer_capacity * 1.5);

                if(new_cap < new_size)
                    new_cap = new_size;

            reserve(new_cap);
        }
       
        std::memcpy(buffer_ptr + buffer_size , txt, txt_size + 1);
        buffer_size = new_size;
    }


    myString& myString::operator+=(const myString& other)
    {
        append(other.c_str());
        return *this;
    }
}

