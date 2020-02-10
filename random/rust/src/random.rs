use rand::Rng;

pub struct RandomStruct {
    pub iteration: u16,
    pub range: u16,
    pub number: u16, //same datatype as range
}

//random-test.rs
pub fn random_test(iterations: u16, range: u16) -> Vec<RandomStruct> {
    //random variable
    let mut rng = rand::thread_rng();
    let mut rd: Vec<RandomStruct> = Vec::new();

    for _i in 2..iterations {
        let x =  rng.gen_range(0, range);
        let y = rng.gen_range(0, range);

        if x == y {
            rd.push(RandomStruct {
                iteration: _i,
                range: range,
                number: x,
            });
        }
    }
    return rd;
}