fn main() {
    //let phrase = String::from("What do you think, Pam?");
    let phrase = String::from("hello world test thest apple");

    // rules
    // 1. the first consonant is moved at the end, and -ay is added (first -> irst-fay)
    // 2. words that start with a vowel have -hay appended (apple -> apple-hay)
    // 3. if a word starts with the 'th' digraph both letters will be appended (think -> ink-thay)

    //add easily readable option (irst-fay/irstfay)
    let readable: bool = true;
    
    let words: Vec<&str> = phrase.split(' ').collect();
    let mut char_words: Vec<Vec<char>> = vec![vec![]];

    //removing the first empty element
    char_words.pop();

    for &x in words.iter() {
        char_words.push(x.to_string().chars().collect());
    }

    // new variable, because of mutability
    let mut new_words: Vec<String> = vec![];

    // determining, if the first letter is vowel or consonant
    for word in char_words.iter() {
        let mut new_word = word.to_vec();

        if word[0] == 't' && word[1] == 'h' {
            let first: char = new_word[0];
            let second: char = new_word[1];
            new_word.remove(0);
            // remove twice at index 0, because content will automatically shift
            new_word.remove(0);
            
            if readable {
                new_word.push('-');
            }

            new_word.push(first);
            new_word.push(second);
            new_word.push('a');
            new_word.push('y');

        } else if is_consonant(word[0]) {
            let first: char = new_word[0];
            new_word.remove(0);

            if readable {
                new_word.push('-');
            }

            new_word.push(first);
            new_word.push('a');
            new_word.push('y');
        } else if is_vowel(word[0]) {
            if readable {
                new_word.push('-');
            }

            new_word.push('h');
            new_word.push('a');
            new_word.push('y');
        }

        new_word.push(' ');
        new_words.push(new_word.into_iter().collect());
    }

    // converting the vector to strings
    let pig_latin = &new_words.into_iter().collect::<String>();
    println!("phrase:\n\t{}\n\npig latin:\n\t{}", phrase, pig_latin);
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
