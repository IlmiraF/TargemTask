#pragma once

#include <ostream>

class String
{
public:
    // ctors/dtor
                            String() : size(0), data(nullptr)   {}


                            String( const char* cstr );
                            String( const String& str );
                            String( String&& str ) noexcept;


                            ~String();

    ///
    size_t                  Length() const noexcept     {   return size;    }
    const char*             GetData() const noexcept    {   return data;    }

    ///
    String&                 operator =( const String& other );
    String&                 operator =( String&& other ) noexcept;

    ///
    char&                   operator []( const size_t pos ) const;
    String&                 operator +=( const String& other);
    String&                 operator +=( const char* cstr);
    bool                    operator <( const String& other ) const;

    ///
    friend const String     operator +( const String& lstr, const String& rstr );
    friend const String     operator +( const String& lstr, const char* rstr );
    friend const String     operator +( const char* lstr, const String& rstr );

    ///
    friend std::ostream&    operator <<( std::ostream& os, const String& str );
    friend std::istream&    operator >>( std::istream& is, String& str );

    ///
    friend bool             operator ==( const String& lstr, const String& rstr );
    friend bool             operator ==( const String& lstr, const char* rstr );
    friend bool             operator !=( const String& lstr, const String& rstr );

private:
    //
    size_t                  size;
    char*                   data;


    void                    Clear() noexcept;
};