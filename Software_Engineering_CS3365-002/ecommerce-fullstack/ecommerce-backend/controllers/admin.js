const { errorHandler } = require("../utils");
const jwt = require("jsonwebtoken");
const Product = require("../models/product");
const Order = require("../models/order");

exports.postLogin = (req, res, next) => {
  let { email, password } = req.body;
  email = email.trim();

  if (email !== process.env.ADMIN_EMAIL) {
    return errorHandler(next, "Wrong email!", 422);
  }
  if (password !== process.env.ADMIN_PASSWORD) {
    return errorHandler(next, "Wrong password!", 422);
  }

  const token = jwt.sign({ email }, process.env.TOKEN_SECRET, {
    expiresIn: "3d",
  });
  res.json({ token });
};

exports.getIsLogin = (req, res, next) => res.json({ message: "Logged In" });

exports.getProducts = async (req, res, next) => {
  try {
    let products = await Product.find()
      .populate("category")
      .populate("reviews.user")
      .sort({ created: -1 })
      .exec();

    const formattedProducts = products.map((product) => {
      let imageUrl = null;
      if (product.image instanceof Buffer) {
        const base64Image = product.image.toString("base64");
        imageUrl = `data:image/jpeg;base64,${base64Image}`;
      }

      return {
        _id: product._id,
        name: product.name,
        description: product.description,
        imageUrl,
        category: product.category,
        quantity: product.quantity,
        sold: product.sold,
        price: product.price,
        created: product.created,
        reviews: product.reviews,
        rating: product.rating,
        status: product.status,
      };
    });

    res.json({ products: formattedProducts });
  } catch (error) {
    errorHandler(next, error.message);
  }
};

exports.getProduct = async (req, res, next) => {
  const { id } = req.params;

  try {
    const product = await Product.findById(id)
      .populate("category")
      .populate("reviews.user", "name");

    if (!product) return res.status(404).json({ error: "Product not found" });

    let imageUrl = null;
    if (product.image instanceof Buffer) {
      const base64Image = product.image.toString("base64");
      imageUrl = `data:image/jpeg;base64,${base64Image}`;
    }

    const formattedProduct = {
      _id: product._id,
      name: product.name,
      description: product.description,
      imageUrl,
      category: product.category,
      quantity: product.quantity,
      sold: product.sold,
      price: product.price,
      created: product.created,
      reviews: product.reviews,
      rating: product.rating,
      status: product.status,
    };

    res.json({ product: formattedProduct });
  } catch (error) {
    errorHandler(next, error.message);
  }
};

exports.getOrders = async (req, res, next) => {
  try {
    const orders = await Order.find()
      .populate("items.product")
      .sort({ date: -1 })
      .exec();
    res.json({ orders });
  } catch (error) {
    errorHandler(next, error.message);
  }
};

exports.getOrder = async (req, res, next) => {
  const { id } = req.params;

  try {
    const order = await Order.findById(id).populate("items.product");
    res.json({ order });
  } catch (error) {
    errorHandler(next, error.message);
  }
};
