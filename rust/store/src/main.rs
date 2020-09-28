mod store;
mod product;
mod cashier;

fn main() {
    println!("Hello, world!");

    let kasse1: cashier::Cashier = cashier::Cashier::new_cashier(1, 100);
    let kekse: product::Product = product::Product::new_product("keks", 2, 12);

    let kassen: [cashier::Cashier; 8] = [kasse1; 8];
    let produkte: [product::Product; 255] = [kekse; 255];

    let migi: store::Store = store::Store::new_store("migi", kassen, produkte);
}
