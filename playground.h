#ifndef PLAYGROUND_HEADER
#define PLAYGROUND_HEADER

#include <ratio>

namespace playground
{
    template<class Dimension, class Tag>
    struct distance
    {
        using tag = Tag;
        using dimension = Dimension;

        constexpr explicit distance(int i) : m_i(i){}
        int m_i;
    };

    template<class Dimension,class Tag>
    bool operator ==(const distance<Dimension, Tag>& lhs, const distance<Dimension, Tag>& rhs)
    {
        return lhs.m_i == rhs.m_i;
    }

} // namespace playground

#endif //PLAYGROUND_HEADER