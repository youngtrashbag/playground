use std::io::{self, BufReader};
use std::io::prelude::*;
use std::fs::File;

fn main() {
    // words are separated by newlines
    const wordlist: &str = "./words.txt";

    let words;
}

fn readLines(path: String) -> io::Result<Ok(str), std::error> {
    let f = File::open(path)?;
    let f = BufReader::new(f);
}
