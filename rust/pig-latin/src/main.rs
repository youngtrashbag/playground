fn main() {
    //let phrase = String::from("What do you think, Pam?");
    let phrase = String::from("hello world test thest apple");

    // rules
    // 1. the first consonant is moved at the end, and -ay is added (first -> irst-fay)
    // 2. words that start with a vowel have -hay appended (apple -> apple-hay)
    // 3. if a word starts with the 'th' digraph both letters will be appended (think -> ink-thay)
    
    let vowels: Vec<char> = vec!['a', 'e', 'i', 'o', 'u'];
    let consonants: Vec<char> = vec!['b', 'c', 'd', 'f', 'g',
    'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v',
    'w', 'x', 'y', 'z', ];

    //let alphabet: Vec<char> = vec!['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];

    let mut words: Vec<String> = vec![String::from("")];

    for word in phrase.split_ascii_whitespace() {
        for letter in &vowels {
            // word starts with a vowel
            if word.chars().next() == Some(*letter) {
                let mut new: String = String::from(word.trim_start());
                new = format!("{}-{}ay", new, letter);
                words.push(new);
            }
        }
        for letter in &consonants {
            // word starts with digraph (th)
            if word.chars().next() == Some('t') && word.chars().next() == Some('h') {
                let mut new: String = String::from(word.trim_start());
                new = format!("{}-thay", new);
                words.push(new);
            }
            else if word.chars().next() == Some(*letter) {
                let mut new: String = String::from(word.trim_start());
                new = format!("{}-{}ay", new, letter);
                words.push(new);
            }
        }
    }

    println!("phrase: {}\npig lating: {:?}", phrase, words);

    // fucc this, i need to implement this later, im not good enough yet ..
}
