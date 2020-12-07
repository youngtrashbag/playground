extern crate rand;
use rand::prelude::*;
mod utils;

fn main() {
    // words are separated by newlines
    let words: Vec<String> = utils::file_to_vec("words.txt".to_string());

    // select a random word
    let mut rng = rand::thread_rng();
    let num: usize = rng.gen_range(0, words.len());
    // this should create a copy I think... right ?
    let word: String = words[num].chars().collect::<String>();

    println!("word: {:#?}", word);
}
