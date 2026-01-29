const { errorHandler } = require("../utils");
const Product = require("../models/product");
const Category = require("../models/category");

exports.postProduct = async (req, res, next) => {
  let { name, description, image, category, quantity, price, status } =
    req.body;
  name = name.trim();
  description = description.trim();

  try {
    if (!name.length) {
      return errorHandler(next, "Enter name!", 422);
    }
    if (!description.length) {
      return errorHandler(next, "Enter description!", 422);
    }
    if (!image.length) {
      return errorHandler(next, "Upload image!", 422);
    }
    const categoryExists = await Category.findById(category);
    if (!categoryExists) {
      return errorHandler(next, "Category not found!", 422);
    }
    if (!quantity) {
      return errorHandler(next, "Quantity shouldn't be 0!", 422);
    }
    if (!price) {
      return errorHandler(next, "Price shouldn't be 0!", 422);
    }
    if (status !== "PRIVATE" && status !== "PUBLIC") {
      return errorHandler(
        next,
        "Status should either be PRIVATE or PUBLIC!",
        422
      );
    }

    let product = new Product({
      name,
      description,
      image,
      category,
      quantity,
      price,
      status,
    });
    await product.save();
    product = await Product.populate(product, { path: "category" });
    res.json({ product });
  } catch (error) {
    console.log(error);
    errorHandler(next, error.message);
  }
};

exports.patchProduct = async (req, res, next) => {
  const { id } = req.params;

  let { name, description, image, category, quantity, price, status } =
    req.body;
  name = name.trim();
  description = description.trim();

  try {
    if (!name.length) {
      return errorHandler(next, "Enter name!", 422);
    }
    if (!description.length) {
      return errorHandler(next, "Enter description!", 422);
    }
    if (!image.length) {
      return errorHandler(next, "Upload image!", 422);
    }
    const categoryExists = await Category.findById(category);
    if (!categoryExists) {
      return errorHandler(next, "Category not found!", 422);
    }
    if (!price) {
      return errorHandler(next, "Price shouldn't be 0!", 422);
    }
    if (status !== "PRIVATE" && status !== "PUBLIC") {
      return errorHandler(
        next,
        "Status should either be PRIVATE or PUBLIC!",
        422
      );
    }

    let product = await Product.findById(id);
    product.name = name;
    product.description = description;
    product.image = image;
    product.category = category;
    product.status = status;
    product.quantity = quantity;
    product.price = price;
    await product.save();
    product = await Product.populate(product, { path: "category" });
    res.json({ product });
  } catch (error) {
    errorHandler(next, error.message);
  }
};

exports.deleteProduct = async (req, res, next) => {
  const { id } = req.params;

  try {
    const product = await Product.findOneAndDelete({ _id: id });
    res.json({ product });
  } catch (error) {
    errorHandler(next, error.message);
  }
};

exports.getProduct = async (req, res, next) => {
  const { id } = req.params;
  try {
    const product = await Product.findOne({
      _id: id,
      status: "PUBLIC",
    })
      .populate("category")
      .populate("reviews.user", "name");

    if (!product) return res.status(404).json({ error: "Product not found" });

    const base64Image = product.image?.toString("base64") || null;
    const imageUrl = base64Image
      ? `data:image/jpeg;base64,${base64Image}`
      : null;

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

exports.getProducts = async (req, res, next) => {
  const { search } = req.query;
  const regex = new RegExp(search, "gi");

  try {
    let query = { status: "PUBLIC" };
    if (search) {
      query.name = { $regex: regex };
    }

    let products = await Product.find(query)
      .populate("category")
      .sort({ created: -1 })
      .exec();

    const formattedProducts = products.map((product) => {
      const base64Image = product.image?.toString("base64") || null;
      const imageUrl = base64Image
        ? `data:image/jpeg;base64,${base64Image}`
        : null;

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

exports.getCategoryProducts = async (req, res, next) => {
  const { id } = req.params;
  try {
    let products = await Product.find({
      category: id,
      status: "PUBLIC",
    })
      .populate("category")
      .sort({ created: -1 })
      .exec();

    const formattedProducts = products.map((product) => {
      const base64Image = product.image?.toString("base64") || null;
      const imageUrl = base64Image
        ? `data:image/jpeg;base64,${base64Image}`
        : null;

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

exports.postReview = async (req, res, next) => {
  const { id } = req.params;
  let { order, rating, comment } = req.body;
  comment = comment.trim();

  if (!comment.length) {
    errorHandler(next, "Enter the review!", 422);
  }
  if (rating < 1 || rating > 5) {
    errorHandler(next, "Give rating!", 422);
  }

  try {
    let product = await Product.findById(id);
    product = await product.addReview(req.userId, order, rating, comment);
    res.json({ product });
  } catch (error) {
    errorHandler(next, error.message);
  }
};
