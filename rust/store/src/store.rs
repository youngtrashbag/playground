use crate::{cashier::Cashier, product::Product};

pub struct Store {
    pub name: &'static str,
    pub cashiers: [Cashier; 8],
    pub products: [Product; 255]
}

impl Store {
    pub fn new_store(name: &'static str, cashiers: [Cashier; 8], products: [Product; 255]) -> Self {
        Store {
            name,
            cashiers,
            products
        }
    }
}
