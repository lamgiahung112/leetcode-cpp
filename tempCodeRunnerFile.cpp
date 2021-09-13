int slen = s.length();

    map<char, int> meta;
    int len = 0;
    int base = -1;
    for(int i = 0; i < slen; i++)
    {
        auto iter = meta.find(s[i]);
        if(iter != meta.end())
            base = MAX(base, iter->second);

        meta[s[i]] = i;
        
        len = MAX(len, i-base);
    }
    return len;