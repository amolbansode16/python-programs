def count_vowel(str):
    count=0;
    for alph in str:
        if alph.lower()in ['a','e','i','o','u']:
	    count+=1
            
    return count

if __name__=="__main__":
    str=raw_input("enter string:")
    count_vowel(str)
