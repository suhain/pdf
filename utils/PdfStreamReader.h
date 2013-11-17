/* 
 * File:   PdfStreamReader.h
 * Author: hus
 *
 * Created on November 14, 2013, 8:33 PM
 */

#ifndef PDFSTREAMREADER_H
#define	PDFSTREAMREADER_H

#include <fstream>
#include <string>

namespace pdf
{
    template<typename T, typename U> class PdfStreamReader;
    
    typedef PdfStreamReader<char, size_t> reader;

    template<typename T, typename U>
    class PdfStreamReader
    {
        T* buf;
        U max_len;
        U _len;
        
        // unavailable members:
        // copy constructor
        PdfStreamReader(PdfStreamReader&);
    public:
        PdfStreamReader(std::ifstream& f, U len = 1024)
        {
            max_len = len;
            if (f.is_open())
            {
                std::streamsize bytes_read = 0;
                buf = new T[max_len];
                do
                {
                    f.read(buf, sizeof(buf) / sizeof(T));
                    bytes_read = f.gcount();
                    _len = bytes_read;
                    std::cout << std::string(buf, buf + _len);
                } 
                while(_len == max_len);
                std::cout << std::string(buf, buf + _len);
            }
        }
        
        virtual ~PdfStreamReader()
        {
            delete[] buf;
        }
        
//        const std::string operator*()
//        {
//            return std::string(buf, buf + max_len);
//        }
            
    };

};

#endif	/* PDFSTREAMREADER_H */

