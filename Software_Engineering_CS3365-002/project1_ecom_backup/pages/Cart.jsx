import React from 'react';
import { useCart } from '../context/CartContext';

export default function Cart() {
  const { cartItems, dispatch } = useCart();

  const total = cartItems.reduce((sum, item) => sum + item.price * item.quantity, 0);

  return (
    <div className="container">
      <h2>Your Shopping Cart</h2>
      {cartItems.length === 0 ? (
        <p>Your cart is empty.</p>
      ) : (
        <>
          <ul>
            {cartItems.map(item => (
              <li className="cart-item">
                <strong>{item.name}</strong> — ${item.price} × {item.quantity}
                <button
                  onClick={() => dispatch({ type: 'REMOVE_FROM_CART', payload: item.id })}
                  style={{ marginLeft: '1rem' }}
                >
                  Remove
                </button>
              </li>
            ))}
          </ul>
          <h3>Total: ${total.toFixed(2)}</h3>
        </>
      )}
    </div>
  );
}
