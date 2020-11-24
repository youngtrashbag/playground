// rules
// 1. the first consonant is moved at the end, and -ay is added (first -> irst-fay)
// 2. words that start with a vowel have -hay appended (apple -> apple-hay)
// 3. if a word starts with the 'th' digraph both letters will be appended (think -> ink-thay)

// NOTE: this program assumes all letters to be lowercase
//          also, you cant pass a sentence as argument yet....

use std::env;

// constants (I'm using them similarly as in C/C++)
const EASY_READABILITY: bool = true;

fn main() {
    //let phrase = String::from("What do you think, Pam?");
    let mut phrase = String::from("hello world test thest apple");

    /*
    // parse arguments
    let mut args: Vec<String> = env::args().collect();

    // one argument passed (first arg is always program file/name)
    if args.len() >= 2 {
        phrase = "".to_string();
        args.remove(0);

        for element in args {
            phrase += &element;
            phrase += " ";
        }
    }
    */
    
    let words: Vec<&str> = phrase.split(' ').collect();
    let mut char_words: Vec<Vec<char>> = vec![vec![]];

    //removing the first empty element of vector
    char_words.pop();

    for &word in words.iter() {
        char_words.push(word.chars().collect());
    }

    // new variable, because of mutability
    let mut new_words: Vec<String> = vec![];

    // determining, if the first letter is vowel or consonant
    for word in char_words.iter() {
        //let copy_of_vec = word.to_vec();
        let mut pig_latinified_word = pig_latinify(word.to_vec());

        pig_latinified_word.push(' ');
        new_words.push(pig_latinified_word.into_iter().collect());
    }

    // converting the vector to strings
    let pig_latin = &new_words.into_iter().collect::<String>();
    println!("phrase:\n\t{}\n\npig latin:\n\t{}", phrase, pig_latin);
}

fn pig_latinify(word: Vec<char>) -> Vec<char>{
    let mut new_word = word.to_vec();

    if word[1] == 'h' {
        let first: char = new_word[0];
        let second: char = new_word[1];
        new_word.remove(0);
        // remove twice at index 0, because content will automatically shift
        new_word.remove(0);
        
        if EASY_READABILITY {
            new_word.push('-');
        }

        new_word.push(first);
        new_word.push(second);
        new_word.push('a');
        new_word.push('y');

    } else if is_consonant(word[0]) {
        let first: char = word[0];
        new_word.remove(0);

        if EASY_READABILITY {
            new_word.push('-');
        }

        new_word.push(first);
        new_word.push('a');
        new_word.push('y');
    } else if is_vowel(word[0]) {
        if EASY_READABILITY {
            new_word.push('-');
        }

        new_word.push('h');
        new_word.push('a');
        new_word.push('y');
    }

    new_word
}

fn is_consonant(letter: char) -> bool {
    let consonants: Vec<char> = vec!['b', 'c', 'd', 'f', 'g',
    'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v',
    'w', 'x', 'y', 'z', ];

    let mut yes: bool = false;

    for cons in consonants.iter() {
        if letter == *cons {
            yes = true;
        }
    }

    yes
}

fn is_vowel(letter: char) -> bool {
    let vowels: Vec<char> = vec!['a', 'e', 'i', 'o', 'u'];

    let mut yes: bool = false;

    for vow in vowels.iter() {
        if letter == *vow {
            yes = true;
        }
    }

    yes
}

#[cfg(test)]
mod tests {
    use super::*;
    
    #[test]
    fn consonant() {
        let word: Vec<char> = "ketamine".chars().collect();
        let changed: Vec<char> = "etamine-kay".chars().collect();
        assert_eq!(pig_latinify(word), changed);
    }

    #[test]
    fn vowel() {
        let word: Vec<char> = "apple".chars().collect();
        let changed: Vec<char> = "apple-hay".chars().collect();
        assert_eq!(pig_latinify(word), changed);
    }

    #[test]
    fn th() {
        let word: Vec<char> = "thalamus".chars().collect();
        let changed: Vec<char> = "alamus-thay".chars().collect();
        assert_eq!(pig_latinify(word), changed);
    }

    fn ph() {
        let word: Vec<char> = "phracking".chars().collect();
        let changed: Vec<char> = "racking-phay".chars().collect();
        assert_eq!(pig_latinify(word), changed);
    }

}
