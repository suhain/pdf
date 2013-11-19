#pragma once

#ifndef STREAMREADER_H
#define STREAMREADER_H

#include <fstream>
#include <exception>

namespace pdf
{
    template<typename BufferType, typename BufferLengthType>
    class StreamReader;

    typedef StreamReader<char, size_t> reader;

    template<typename BufferType, typename BufferLengthType>
    class StreamReader
    {
        BufferType* _buffer;
        BufferLengthType _max_buffer_length;
        BufferLengthType _length;
        std::ifstream _input_file_stream;
        
    public:

        StreamReader(const char* filename, BufferLengthType _len = 1024) :
        _max_buffer_length(_len),
        _length(0)
        {
            _input_file_stream.open(filename, std::ios::binary);
            _buffer = new BufferType[_max_buffer_length];
        }

        const bool operator()()
        {
            if (_input_file_stream.is_open())
            {
                _input_file_stream.read(_buffer, _max_buffer_length);
                _length = (BufferLengthType)_input_file_stream.gcount();
            }
            else
            {
                throw new std::string("error while handling file");
            }
            return _length > 0;
        }

        const BufferLengthType& length() const
        {
            return _length;
        }

        const BufferType& operator[](BufferLengthType index) const
        {
            return _buffer[index];
        }
        
        BufferType& operator[](BufferLengthType index)
        {
            return _buffer[index];
        }

        virtual ~StreamReader()
        {
            _input_file_stream.close();
            delete[] _buffer;
        }

    };

};

#endif /* STREAMREADER_H */

