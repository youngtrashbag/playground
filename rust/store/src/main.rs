mod store;
mod product;
mod cashier;

fn main() {
    let kasse1: cashier::Cashier = cashier::Cashier::new_cashier(1, 100);
    let kekse: product::Product = product::Product::new_product("keks", 2, 12);

    // loads 8 copies of kasse1 into kassen
    let kassen: [cashier::Cashier; 8] = [kasse1; 8];
    // loads 255 copies of kekse into produkte
    let produkte: [product::Product; 255] = [kekse; 255];

    let migi: store::Store = store::Store::new_store("migi", kassen, produkte);

    println!("{}", migi.cashiers.len());
}
